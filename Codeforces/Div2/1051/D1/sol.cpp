/**
 *    author:  feev1x
 *    created: 17.09.2025 21:07:40
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

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::vector dp(n + 1, std::vector(n + 1, std::vector<int>(n + 1)));

        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                for (int k = 0; (j == 0 && k == 0) || k < j; ++k) {
                    add_self(dp[i][j][k], dp[i - 1][j][k]);

                    if (a[i] < k)
                        continue;

                    if (a[i] >= j)
                        add_self(dp[i][a[i]][k], dp[i - 1][j][k]);
                    else if (a[i] >= k)
                        add_self(dp[i][j][a[i]], dp[i - 1][j][k]);
                }

        int res = 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < i; ++j)
                add_self(res, dp[n][i][j]);

        std::cout << res << '\n';
    }
    return 0;
}
