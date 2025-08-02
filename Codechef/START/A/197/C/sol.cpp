/**
 *    author:  feev1x
 *    created: 30.07.2025 21:02:50
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        std::vector<double> a(n + 1), b(n + 1), dp(n + 2, 1e18);

        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];

        dp[n + 1] = 0;

        double ls = dp[1];
        for (int it = 0; ; ++it) {
            double sum = std::accumulate(dp.begin() + 1, dp.end(), 0.0);

            for (int i = n; i >= 1; --i)
                dp[i] = std::min(a[i] + dp[i + 1], b[i] + sum / (n + 1));

            if (dp[1] == ls)
                break;

            ls = dp[1];
        }

        std::cout << std::fixed << std::setprecision(10) << dp[1] << '\n';
    }

    return 0;
}
