/**
 *    author:  feev1x
 *    created: 05.03.2025 15:12:04
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<std::vector<int64_t>> t, cost;
    std::vector<int64_t> a, op;
    int n;
    int64_t mx;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].emplace_back(a[tl]);
            op[v] = 0;
            cost[v].resize(1);

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        int64_t max = 0;
        for (int i = tl; i <= tr; ++i) {
            max = std::max(max, a[i]);

            t[v].emplace_back(max);

            op[v] += max - a[i];
        }

        cost[v].resize(t[v].size());

        for (int i = 1; i < t[v].size(); ++i) {
            cost[v][i] = (t[v][i] - t[v][i - 1]) * i + cost[v][i - 1];
        }
    }
    
    Segtree(int _n, std::vector<int64_t> _a) : n(_n), a(_a) {
        t.resize(4 * n + 1);
        cost.resize(4 * n + 1);
        op.resize(4 * n + 1);

        build(1, 1, n);
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            int64_t i = std::upper_bound(t[v].begin(), t[v].end(), mx) - t[v].begin(), res = op[v];

            if (i) {
                i--;

                res += (mx - t[v][i]) * (i + 1) + cost[v][i];
            }

            mx = std::max(mx, t[v].back());

            return res;
        }

        int tm = tl + tr >> 1;
        
        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void build() {
        build(1, 1, n);
    }

    inline int64_t get(int l, int r) {
        mx = 0;

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
        int l, r; std::cin >> l >> r;

        std::cout << t.get(l, r) << '\n';
    }
    return 0;
}
