#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

struct Node {
    int mx = -INF, mnmn = INF, mnmn2 = INF, psh = 0, mn = INF, mn2 = INF;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    inline Node comb(const Node &a, const Node &b) {
        Node res;

        res.mx = std::max(a.mx, b.mx);

        if (a.mn == b.mn) {
            res.mnmn = std::min(a.mnmn, b.mnmn);
            res.mn = a.mn;
            
            res.mnmn2 = std::min(a.mnmn2, b.mnmn2);
            if (a.mn2 == b.mn2) {
                res.mn2 = a.mn2;
            } else if (a.mn2 > b.mn2) {
                res.mn2 = b.mn2;
            } else { 
                res.mn2 = a.mn2;
            }
        } else if (a.mn > b.mn) {
            res.mnmn = b.mnmn;
            res.mn = b.mn;

            res.mnmn2 = std::min({a.mnmn, a.mnmn2, b.mnmn2});
            if (a.mn == b.mn2) {
                res.mn2 = b.mn2;
            } else if (a.mn > b.mn2) {
                res.mn2 = b.mn2;
            } else {
                res.mn2 = a.mn;
            }

        } else {
            res.mnmn = a.mnmn;
            res.mn = a.mn;

            res.mnmn2 = std::min({a.mnmn2, b.mnmn, b.mnmn2});
            if (b.mn == a.mn2) {
                res.mn2 = a.mn2;
            } else if (b.mn > a.mn2) {
                res.mn2 = a.mn2;
            } else {
                res.mn2 = b.mn;
            }
        }

        return res;
    }

    inline void push(int v) {
        if (t[v].psh) {
            if (t[v].psh > t[v << 1].mn) {
                t[v << 1].mnmn += t[v].psh - t[v << 1].mn;
                t[v << 1].mn = t[v].psh;
                t[v << 1].psh = t[v].psh;

                chmax(t[v << 1].mx, t[v << 1].psh);
            }

            if (t[v].psh > t[v << 1 | 1].mn) {
                t[v << 1 | 1].mnmn += t[v].psh - t[v << 1 | 1].mn;
                t[v << 1 | 1].mn = t[v].psh;
                t[v << 1 | 1].psh = t[v].psh;

                chmax(t[v << 1 | 1].mx, t[v << 1 | 1].psh);
            }

            t[v].psh = 0;
        }
    }

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].mnmn = 1;
            t[v].mx = tl;
            t[v].mn = tl;
            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    Segtree(int n) : n(n) {
        t.resize(4 * n);

        build(1, 1, n);
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr || x <= t[v].mn) {
            return;
        }

        if (l <= tl && tr <= r && t[v].mn2 > x) {
            if (x > t[v].mn) {
                t[v].mnmn += x - t[v].mn;
                t[v].mn = x;
                t[v].psh = x;

                chmax(t[v].mx, x);
            }

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    
    inline int get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return INF;
        }

        if (tl == tr && tl == 1) {
//            std::cout << t[v].mnmn << '\n';
        }

        if (l <= tl && tr <= r) {
            return std::min(t[v].mnmn, t[v].mnmn2);
        }

        push(v);

        int tm = tl + tr >> 1;

        return std::min(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline int fnd(int v, int tl, int tr, int x) {
        if (tl == tr) {
            if (t[v].mx >= x) {
                return -1;
            }

            return tl;
        }

        push(v);

        int tm = tl + tr >> 1;
        if (t[v << 1].mx >= x) {
            return fnd(v << 1, tl, tm, x);
        }

        int got = fnd(v << 1 | 1, tm + 1, tr, x);

        if (got == -1) {
            return tm;
        }

        return got;
    }

    inline void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    inline int fnd(int x) {
        return fnd(1, 1, n, x);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        if (a[i] <= n) {
            pos[a[i]].emplace_back(i);
        }
    }


    int mx = n;
    Segtree t(n); // chmax
    for (int k = 0; k <= n; ++k) {
        std::reverse(pos[k].begin(), pos[k].end());


        int ls = n + 1;

        int res = -1;

        pos[k].emplace_back(0);
        for (auto i: pos[k]) {
            int ps = t.fnd(ls);

            if (ps > i && mx >= i + 1) {
                int got = t.get(i + 1, std::min(mx, ps));

//                std::cout << "\n CHECK " << t.get(2, 2) << ' ' << i << ' ' << std::min(mx, ps) << ' ' << ls <<  ' ' << t.get(1, 1) << '\n';

                if (res == -1 || res > got) {
                    res = got;
                }
            }

            if (ls != n + 1) {
                t.update(i + 1, ls, ls);
//                std::cout << "\n GO " << t.get(i + 1, i + 1) << ' ' << i + 1 << ' ' << ls << '\n';
            } else {
                mx = std::min(mx, i);
            }

            ls = i;
        }



        if (k) {
            std::cout << res << " \n"[k == n];
        }
    }

    return 0;
}
