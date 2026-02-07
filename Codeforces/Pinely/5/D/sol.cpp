/**
 *    author:  feev1x
 *    created: 30.10.2025 23:10:05
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

        std::vector<int> a(n), dp(n);
        std::vector<std::vector<int>> pos(n + 2);

        int res = 0, res1 = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];

            pos[a[i]].emplace_back(i);
        }

        for (int val = n; val >= 1; --val) {
            int ans = 0, idx = 0, old = -1;

            for (auto i: pos[val]) {
                if (pos[val + 1].size() && pos[val + 1][0] < i) {
                    int j = *--std::lower_bound(pos[val + 1].begin(), pos[val + 1].end(), i);

                    dp[i] = std::max(dp[i], dp[j] + 1);
                }

                if (old != -1)
                    dp[i] = std::max(dp[i], dp[old] + 1);
                
                dp[i] = std::max(dp[i], res1 + idx + 1);
                ans = std::max(ans, dp[i]);

                idx++;
                old = i;
            }

            res1 = res;
            res = std::max(res, ans);
        }

        std::cout << n - res << '\n';
    }
    return 0;
}
