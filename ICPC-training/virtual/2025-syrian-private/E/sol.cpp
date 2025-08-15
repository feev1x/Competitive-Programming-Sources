/**
 *    author:  feev1x
 *    created: 13.08.2025 15:29:40
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<bool> cnt(n + 1);
        std::vector<std::array<int, 2>> dp(n + 1, {0, 0});
        for (int i = 1; i <= n; ++i) {
            int u; std::cin >> u;

            cnt[i] = __builtin_popcount(u) % 2;
            dp[i][cnt[i]] = 1;
        }

        
        int sum0 = 0, sum1 = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i]) {
                add_self(dp[i][0], sum1);
                add_self(dp[i][1], sum0);
            } else {
                add_self(dp[i][0], sum0);
                add_self(dp[i][1], sum1);
            }

            add_self(sum1, dp[i][1]);
            add_self(sum0, dp[i][0]);
        }

        std::cout << sum1 << '\n';
    }
    return 0;
}
