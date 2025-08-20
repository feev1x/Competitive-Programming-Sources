/**
 *    author:  feev1x
 *    created: 20.08.2025 16:20:47
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int N = 30, INF = 2e9;

using arr = std::array<int, N>;

inline int min(int &a, int &b) {
    return a > b ? b : a;
}

struct Segtree {
    std::vector<arr> t;
    arr ar;
    int n;

    Segtree(int _n) : n(_n) {
        for (auto &u: ar)
            u = INF;

        t.assign(2 * n, ar);
    }

    inline arr comb(arr &a, arr &b) {
        arr res;

        for (int i = 0; i < N; ++i)
            res[i] = min(a[i], b[i]);

        return res;
    }
    
    inline void build() {
        for (int i = n - 1; i > 0; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }

    inline arr get(int l, int r) {
        auto res = ar;

        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = comb(res, t[l++]);

            if (r & 1)
                res = comb(t[--r], res);
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int> a(n + 1);
    std::vector<std::array<int64_t, N>> p(n + 1);
    std::vector<int64_t> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        for (int j = 0; a[i] >= (1 << j) && j < N; ++j)
            t.t[i + n - 1][j] = a[i];

        for (int j = 0; j < N; ++j) {
            p[i][j] = p[i - 1][j] + (a[i] < (1 << j) ? a[i] : 0);
            pref[i] = pref[i - 1] + a[i];
        }
    }

    t.build();

    while (q--) {
        int l, r; std::cin >> l >> r;

        auto got = t.get(l, r);
        int64_t res = -1, sum;
        for (int i = 0; i < N; ++i) {
            sum = p[r][i] - p[l - 1][i];

            if (sum >= (1 << i + 1) - 1 || got[i] <= sum + 1 && got[i] < INF)
                continue;

            res = sum + 1;
            break;
        }

        std::cout << (res == -1 ? pref[r] - pref[l - 1] + 1 : res) << '\n';
    }

    return 0;
}
