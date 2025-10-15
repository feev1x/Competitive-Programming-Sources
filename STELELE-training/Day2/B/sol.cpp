/**
 *    author:  feev1x
 *    created: 13.10.2025 09:27:26
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<double> dp(k + 1);

    dp[1] = 1;
    for (int l = 1; l <= n; ++l) {
        std::vector a(k + 1, std::vector<double>(k + 1));
        auto new_dp = dp;

        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j) {
                std::cin >> a[i][j];

                new_dp[j] = std::max(new_dp[j], dp[i] * a[i][j]);
            }

        std::swap(dp, new_dp);
    }

    std::cout << std::fixed << std::setprecision(10) << dp[1] << '\n';
    return 0;
}
