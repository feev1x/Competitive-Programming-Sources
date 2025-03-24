/**
 *    author:  feev1x
 *    created: 06.03.2025 07:27:09
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int64_t> t, fst, d, a;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    Segtree(int _n, std::vector<int64_t> _a) : n(_n), a(_a) {
        t.resize(4 * n + 1);
        d.resize(4 * n + 1);
        fst.resize(4 * n + 1);

        build(1, 1, n);
    }

    inline void push(int v, int tl, int tr) {
        int tm = tl + tr >> 1;
        int64_t szl = tm - tl + 1, szr = tr - tm;

        fst[v << 1] += fst[v];
        d[v << 1] += d[v];
        t[v << 1] += (fst[v] * 2 + d[v] * (szl - 1)) * szl / 2;

        t[v << 1 | 1] += (fst[v] * 2 + d[v] * (szl * 2 + szr - 1)) * szr / 2;
        d[v << 1 | 1] += d[v];
        fst[v << 1 | 1] += fst[v] + d[v] * szl; 

        assert(t[v] == t[v << 1] + t[v << 1 | 1]);

        fst[v] = d[v] = 0;
    }

    inline void update(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            fst[v] += tl - l + 1;
            d[v]++;
            t[v] += (int64_t)((tl - l + 1) * 2 + tr - tl) * (tr - tl + 1) / 2;

            return;
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r);
        update(v << 1 | 1, tm + 1, tr, l, r);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void update(int l, int r) {
        update(1, 1, n, l, r);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    Segtree t(n, a);

    while (q--) {
        int type, l, r; std::cin >> type >> l >> r;

        if (type == 1) {
            t.update(l, r);
        } else {
            std::cout << t.get(l, r) << '\n';
        }
    }
    return 0;
}
