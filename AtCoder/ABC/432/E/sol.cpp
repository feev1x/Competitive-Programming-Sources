/**
 *    author:  feev1x
 *    created: 15.11.2025 18:21:56
**/
#include <bits/stdc++.h>

constexpr int N = 5e5 + 10;

struct Segtree {
    std::vector<int64_t> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] += (tl - 1) * x;
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;
        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void update(int i, int x) {
        update(1, 1, n, i + 1, x);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l + 1, r + 1);
    }
};

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        r++;

        for (; r <= n; r += r & -r)
            p[r] += x;
    }

    inline int get(int r) {
        r++;

        int res = 0;

        for (; r > 0; r -= r & -r)
            res += p[r];

        return res;
    }

    inline int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(N);
    Bit bit(N);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], bit.update(a[i], 1), t.update(a[i], 1);

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int x, y; std::cin >> x >> y;

            bit.update(a[x], -1);
            t.update(a[x], -1);

            a[x] = y;

            bit.update(a[x], 1);
            t.update(a[x], 1);
        } else {
            int64_t l, r; std::cin >> l >> r;

            if (l >= r) {
                std::cout << n * l << '\n';
                continue;
            }

            std::cout << t.get(l, r) + bit.get(l - 1) * l + bit.get(r + 1, N - 4) * r << '\n';
        }
    }

    return 0;
}
