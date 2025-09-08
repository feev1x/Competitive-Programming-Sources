/**
 *    author:  feev1x
 *    created: 28.08.2025 20:36:12
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

        std::vector<std::vector<int>> pos(n + 1);
        std::vector<int> a(n + 1), idx(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            idx[i] = pos[a[i]].size();
            pos[a[i]].emplace_back(i);
        }

        std::vector<int> dp(n + 1), pref(n + 1);
        for (int i = 1; i <= n; ++i) {
            int j = idx[i];

            if (j - a[i] + 1 >= 0)
                dp[i] = pref[pos[a[i]][j - a[i] + 1] - 1] + a[i];

            pref[i] = std::max(pref[i - 1], dp[i]);
        }

        std::cout << pref[n] << '\n';
    }
    return 0;
}
