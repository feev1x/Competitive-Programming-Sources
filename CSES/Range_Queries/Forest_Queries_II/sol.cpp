/**
 *    author:  feev1x
 *    created: 06.03.2025 06:30:22
**/
#include <bits/stdc++.h>

using matrix = std::vector<std::vector<int>>;

struct Bit {
    std::vector<int> p, a;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
        a.resize(n + 1);
    }

    inline void update(int r, int x) {
        a[r] += x;

        for (; r <= n; r += r & -r) {
            p[r] += x;
        }
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r) {
            res += p[r];
        }

        return res;
    }

    inline int get(int l, int r) {
        if (l == r) {
            return a[l];
        }

        return get(r) - get(l - 1);
    }
};

struct Segtree {
    std::vector<Bit> t;
    matrix a;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            for (int i = 1; i <= n; ++i) {
                t[v].update(i, a[tl][i]);
            }

            return;
        }
        
        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = t[v << 1 | 1];

        for (int i = 1; i <= n; ++i) {
            t[v].update(i, t[v << 1].get(i, i));
        }
    }

    Segtree(int _n, matrix _a) : n(_n), a(_a) {
        t.assign(4 * n + 1, Bit(n));

        build(1, 1, n);
    }

    inline void update(int v, int tl, int tr, int i, int j, int x) {
        t[v].update(j, x);

        if (tl == tr) {
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm) {
            update(v << 1, tl, tm, i, j, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, i, j, x);
        }
    }

    inline int get(int v, int tl, int tr, int l1, int l2, int r1, int r2) {
        if (l1 > tr || tl > r1) {
            return 0;
        }

        if (l1 <= tl && tr <= r1) {
            return t[v].get(l2, r2);
        }

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, l1, l2, r1, r2) + get(v << 1 | 1, tm + 1, tr, l1, l2, r1, r2);
    }

    inline void update(int i, int j, int x) {
        update(1, 1, n, i, j, x);
    }

    inline int get(int x1, int y1, int x2, int y2) {
        return get(1, 1, n, x1, y1, x2, y2);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    matrix a(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;

        s = " " + s;

        for (int j = 1; j <= n; ++j) {
            a[i][j] = (s[j] == '*');
        }
    }

    Segtree t(n, a);

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int x, y; std::cin >> x >> y;

            if (a[x][y]) {
                t.update(x, y, -1);
            } else {
                t.update(x, y, 1);
            }

            a[x][y] ^= 1;
        } else {
            int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

            std::cout << t.get(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}
