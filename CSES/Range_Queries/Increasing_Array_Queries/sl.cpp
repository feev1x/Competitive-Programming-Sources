/**
 *    author:  feev1x
 *    created: 06.03.2025 06:01:29
**/
#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int64_t>(l, r)(rng)

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
            cost[v][i] = (t[v][i] - t[v][i - 1]) * i;
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
    
    int tt = 1;
    while (tt++) {
        int n = rnd(1, 10), q = (1, 5);

        std::vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            a[i] = rnd(1, 20);
        }

        Segtree t(n, a);

        while (q--) {
            int l = rnd(1, n), r = rnd(l, n);

            int64_t res = 0, max = 0;
            for (int i = l; i <= r; ++i) {
                max = std::max(max, a[i]);

                res += max - a[i];
            }

            int64_t got = t.get(l, r);
            if (got == res) {
                continue;
            }

            std::cout << "WA\n";

            std::cout << "N: " << n << "\nArray: ";

            for (int i = 1; i <= n; ++i) {
                std::cout << a[i] << " \n"[i == n];
            }

            std::cout << "Query " << l << ' ' << r << '\n';

            std::cout << "Correct Ans: " << res << '\n';
            std::cout << "Your Ans: " << got << '\n';

            goto Wa;
        }

        std::cout << "Test Passed" << ' ' << tt - 1 << '\n';
        continue;
Wa:
        break;
    }
    return 0;
}
