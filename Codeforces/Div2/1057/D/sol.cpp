/**
 *    author:  feev1x
 *    created: 10.10.2025 21:13:45
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

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        int _t = 5;

        int64_t res = INF;
        while (_t--) {
            std::vector<int64_t> dp(n + 1, INF);

            dp[2] = std::abs(a[1] - a[2]);

            std::vector<int> ar{a[1], a[2], a[3]};
            std::sort(ar.begin(), ar.end());

            dp[3] = std::abs(ar[1] - ar[2]) + std::abs(ar[1] - ar[0]);
            for (int i = 4; i <= n; ++i) {
                ar = {a[i], a[i - 1], a[i - 2]};
                std::sort(ar.begin(), ar.end());

                dp[i] = std::min(dp[i - 2] + std::abs(a[i] - a[i - 1]), dp[i - 3] + std::abs(ar[1] - ar[2]) + std::abs(ar[1] - ar[0]));
            }

            res = std::min(res, dp[n]);

            a.emplace_back(a[1]);

            a.erase(a.begin() + 1);
        }

        std::cout << res << '\n';
    }
    return 0;
}
