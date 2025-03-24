/**
 *    author:  feev1x
 *    created: 04.03.2025 17:07:44
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

struct Segtree {
    std::vector<int64_t> t, psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        psh.resize(4 * n + 1);
    }

    inline void push(int v) {
        if (psh[v] != 0) {
            psh[v << 1] += psh[v];
            psh[v << 1 | 1] += psh[v];
            t[v << 1] += psh[v];
            t[v << 1 | 1] += psh[v];

            psh[v] = 0;
        }
    }

    inline void update(int v, int tl, int tr, int l, int r, int64_t x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            psh[v] += x;
            t[v] += x;

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return -INF;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v);

        int tm = tl + tr >> 1;

        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int l, int r, int64_t x) {
        update(1, 1, n, l, r, x);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int64_t> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        p[i] = p[i - 1] + a[i];

        t.update(i, i, p[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int i, x; std::cin >> i >> x;

            t.update(i, n, x - a[i]);
            a[i] = x;
        } else {
            int l, r; std::cin >> l >> r;

            std::cout << std::max((int64_t)0, t.get(l, r) - t.get(l, l) + a[l]) << '\n';
        }
    }
    return 0;
}
