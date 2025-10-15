/**
 *    author:  feev1x
 *    created: 09.09.2025 21:56:04
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

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;

    if (a < 0)
        a += MOD;
}

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

inline void chmin(int &a, int b) {
    if (a > b)
        a = b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        int k; std::cin >> k;

        std::vector<int> c(k);
        for (auto &u: c)
            std::cin >> u, u--;

        if (m == 1) {
            std::cout << "1\n";
            continue;
        }

        std::vector dp(n + 1, std::vector<std::pair<int, int>>(1 << n, {1, 2}));

        dp[1][0] = {1, 1};
        dp[1][1] = {2, 2};
        for (int i = 2; i <= n; ++i) {
            for (int mask = 0; mask < 1 << i; ++mask) {
                for (auto u: c) {
                    if (u >= i)
                        break;

                    int pref = mask % (1 << u);

                    int suff = (mask | (1 << u)) ^ (1 << u);

                    suff -= pref;

                    suff >>= 1;

                    chmax(dp[i][mask].first, dp[i - 1][pref + suff].second);
                    chmin(dp[i][mask].second, dp[i - 1][pref + suff].first);
                }
            }
        }

        int res = 0;

        std::vector<std::vector<int>> cnt(n + 1, std::vector<int>(n + 1));
        for (int mask = 0; mask < 1 << n; ++mask) {
            int cnt1 = __builtin_popcount(mask), cnt0 = n - cnt1;

            if (dp[n][mask].first == 2)
                cnt[cnt1][cnt0]++;
        }

        for (int x = 1; x <= n; ++x) {
            int y = n - x;

            for (int k = 0; k < m; ++k)
                add_self(res, mul(mul(binpow(k, y), binpow(m - k, x)), cnt[x][y]));
        }

        std::cout << res << '\n';
    }
    return 0;
}
