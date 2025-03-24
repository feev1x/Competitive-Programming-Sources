/**
 *    author:  feev1x
 *    created: 06.03.2025 06:56:35
**/
#include <bits/stdc++.h>

struct Segtree{
    std::vector<int64_t> t, psh_sum, psh_set;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        psh_sum.resize(4 * n + 1);
        psh_set.resize(4 * n + 1);
    }

    inline void v_increase(int v, int tl, int tr, int64_t x) {
        if (psh_sum[v] || !psh_set[v]) {
            psh_sum[v] += x;

            t[v] += (int64_t)(tr - tl + 1) * x;
        } else if (psh_set[v]) {
            psh_set[v] += x;

            t[v] = (int64_t)(tr - tl + 1) * psh_set[v];
        }
    }

    inline void v_set(int v, int tl, int tr, int64_t x) {
        psh_sum[v] = 0;
        psh_set[v] = x;

        t[v] = (int64_t)(tr - tl + 1) * x;
    }

    inline void push(int v, int tl, int tr) {
        int tm = tl + tr >> 1;

        if (psh_sum[v]) {
            v_increase(v << 1, tl, tm, psh_sum[v]);
            v_increase(v << 1 | 1, tm + 1, tr, psh_sum[v]);

            psh_sum[v] = 0;
        } else if (psh_set[v]) {
            v_set(v << 1, tl, tm, psh_set[v]);
            v_set(v << 1 | 1, tm + 1, tr, psh_set[v]);

            psh_set[v] = 0;
        }
    }

    inline void increase(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            v_increase(v, tl, tr, x);

            return;
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        increase(v << 1, tl, tm, l, r, x);
        increase(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline void set(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            v_set(v, tl, tr, x);

            return;
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        set(v << 1, tl, tm, l, r, x);
        set(v << 1 | 1, tm + 1, tr, l, r, x);

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

    inline void increase(int l, int r, int x) {
        increase(1, 1, n, l, r, x);
    }

    inline void set(int l, int r, int x) {
        set(1, 1, n, l, r, x);
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
    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.set(i, i, a[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int a, b, x; std::cin >> a >> b >> x;

            t.increase(a, b, x);
        } else if (type == 2) {
            int a, b, x; std::cin >> a >> b >> x;

            t.set(a, b, x);
        } else {
            int a, b; std::cin >> a >> b;

            std::cout << t.get(a, b) << '\n';
        }
    }
    return 0;
}
