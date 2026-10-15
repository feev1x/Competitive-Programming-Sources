#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

    std::vector<int> t, psh;
    std::stack<std::pair<int, int>> ut, up;
    int n;

    inline void push(int v) {
        if (psh[v] != 1) {
            t[v << 1] = mul(t[v << 1], psh[v]);
            t[v << 1 | 1] = mul(t[v << 1 | 1], psh[v]);
            psh[v << 1] = mul(psh[v << 1], psh[v]);
            psh[v << 1 | 1] = mul(psh[v << 1 | 1], psh[v]);

            psh[v] = 1;
        }
    }

    inline void tpush(int v) {
        if (psh[v] != 1) {
            ut.emplace(v << 1, t[v << 1]);
            ut.emplace(v << 1 | 1, t[v << 1 | 1]);
            up.emplace(v << 1, psh[v << 1]);
            up.emplace(v << 1 | 1, psh[v << 1 | 1]);
            up.emplace(v, psh[v]);
            t[v << 1] = mul(t[v << 1], psh[v]);
            t[v << 1 | 1] = mul(t[v << 1 | 1], psh[v]);
            psh[v << 1] = mul(psh[v << 1], psh[v]);
            psh[v << 1 | 1] = mul(psh[v << 1 | 1], psh[v]);

            psh[v] = 1;
        }
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            t[v] = mul(t[v], x);
            psh[v] = mul(psh[v], x);
            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = t[v << 1];

        add_self(t[v], t[v << 1 | 1]);
    }

    inline void tupdate(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            ut.emplace(v, t[v]);
            up.emplace(v, psh[v]);
            t[v] = mul(t[v], x);
            psh[v] = mul(psh[v], x);
            return;
        }

        tpush(v);

        int tm = tl + tr >> 1;

        tupdate(v << 1, tl, tm, l, r, x);
        tupdate(v << 1 | 1, tm + 1, tr, l, r, x);

        ut.emplace(v, t[v]);

        t[v] = t[v << 1];

        add_self(t[v], t[v << 1 | 1]);
    }

    inline void add(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = x;
            psh[v] = 1;
            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        if (i <= tm) {
            add(v << 1, tl, tm, i, x);
        } else {
            add(v << 1 | 1, tm + 1, tr, i, x);
        }

        t[v] = t[v << 1];

        add_self(t[v], t[v << 1 | 1]);
    }

    inline void tadd(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            ut.emplace(v, t[v]);
            up.emplace(v, psh[v]);
            t[v] = x;
            psh[v] = 1;
            return;
        }

        tpush(v);

        int tm = tl + tr >> 1;

        if (i <= tm) {
            tadd(v << 1, tl, tm, i, x);
        } else {
            tadd(v << 1 | 1, tm + 1, tr, i, x);
        }

        ut.emplace(v, t[v]);
        t[v] = t[v << 1];

        add_self(t[v], t[v << 1 | 1]);
    }

    inline int get() {
        return t[1];
    }

    inline void rollback() {
        while (ut.size()) {
            auto [v, val] = ut.top();

            t[v] = val;
            ut.pop();
        }

        while (up.size()) {
            auto [v, val] = up.top();

            psh[v] = val;
            up.pop();
        }
    }

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r) {
            add_self(p[r], x);
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r) {
            add_self(res, p[r]);
        }

        return res;
    }

    inline int get(int l, int r) {
        int res = get(r);

        add_self(res, -get(l - 1));

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    int sq = std::sqrt(n);

    std::vector<int> a(n + 1), b(n + 1), vala(n + 1), valb(n + 1), ca(n + 1), cb(n + 1), pw(2 * n + 1, 1), pos(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        pos[a[i]] = i;
    }

    for (int i = 1; i <= 2 * n; ++i) {
        pw[i] = mul(pw[i - 1], 2);
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];

        pos[b[i]] = i;
        if (b[i] < a[i]) {
            std::swap(a[i], b[i]);
        }
    }

    Bit sm(2 * n), bg(2 * n);

    int q; std::cin >> q;
    std::vector<int> ans(q);
    std::vector<std::vector<std::tuple<int, int, int>>> qq(n / sq + 1);
    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;

        if (l / sq < r / sq) {
            qq[l / sq].emplace_back(r, l, i);
        } else {
            int res = 0;
            for (int i = l; i <= r; ++i) {
                vala[i] = bg.get(a[i]);
                valb[i] = bg.get(b[i]);
                ca[i] = sm.get(a[i], 2 * n);
                cb[i] = sm.get(b[i], 2 * n);

                sm.update(a[i], 1);
                bg.update(b[i], 1);

                if (!ca[i]) {
                    add_self(res, mul(pw[vala[i]], pw[r - i]));
                }

                if (!cb[i]) {
                    add_self(res, mul(pw[valb[i]], pw[r - i]));
                }
            }

            for (int i = l; i <= r; ++i) {
                sm.update(a[i], -1);
                bg.update(b[i], -1);
            }

            ans[i] = res;
        }
    }

    for (int i = 1; i <= n; ++i) {
        vala[i] = valb[i] = ca[i] = cb[i] = 0;
    }

    t.resize(8 * n);
    psh.assign(8 * n, 1);
    for (int bl = 0; bl <= n / sq; ++bl) {
        std::sort(qq[bl].begin(), qq[bl].end());

        int nw = (bl + 1) * sq;
        for (auto [r, l, i]: qq[bl]) {
            while (nw <= r) {
                int i = nw;

                vala[i] = bg.get(a[i]);
                valb[i] = bg.get(b[i]);
                ca[i] = sm.get(a[i], 2 * n);
                cb[i] = sm.get(b[i], 2 * n);

                sm.update(a[i], 1);
                bg.update(b[i], 1);

                update(1, 1, 2 * n, 1, 2 * n, 2);
                if (!ca[i]) {
                    add(1, 1, 2 * n, a[i], pw[vala[i]]);
                }

                if (!cb[i]) {
                    add(1, 1, 2 * n, b[i], pw[valb[i]]);
                }

                nw++;
            }
            
            int nwl = (bl + 1) * sq - 1;

            while (nwl >= l) {
                int i = nwl;

                if (i != std::get<2>(qq[bl].back())) {
                    tupdate(1, 1, 2 * n, 1, a[i], 0);
                    tupdate(1, 1, 2 * n, b[i], 2 * n, 2);
                    tadd(1, 1, 2 * n, a[i], pw[r - i]);
                    tadd(1, 1, 2 * n, b[i], pw[r - i]);
                } else {
                    update(1, 1, 2 * n, 1, a[i], 0);
                    update(1, 1, 2 * n, b[i], 2 * n, 2);
                    add(1, 1, 2 * n, a[i], pw[r - i]);
                    add(1, 1, 2 * n, b[i], pw[r - i]);
                }

                nwl--;
            }

            ans[i] = get();

            rollback();
        }

        for (int i = (bl + 1) * sq; i < nw; ++i) {
            vala[i] = valb[i] = ca[i] = cb[i] = 0;
            sm.update(a[i], -1);
            bg.update(b[i], -1);
        }

        update(1, 1, 2 * n, 1, 2 * n, 0);
    }

    for (auto u: ans) {
        std::cout << u << '\n';
    }
}

