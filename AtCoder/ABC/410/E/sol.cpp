/**
 *    author:  feev1x
 *    created: 16.08.2025 13:37:03
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

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, h, m; std::cin >> n >> h >> m;

    std::vector<int> a(n + 1), b(n + 1);
    std::vector<int> dp(h + 1, -1);

    dp[h] = m;

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i];

        std::vector<int> new_dp(h + 1, -1);
        for (int j = 0; j <= h; ++j) {
            if (dp[j] == -1)
                continue;

            mx = i - 1;
            
            if (j >= a[i])
                chmax(new_dp[j - a[i]], dp[j]);

            if (dp[j] >= b[i])
                chmax(new_dp[j], dp[j] - b[i]);
        }

        dp = new_dp;
    }

    for (int j = 0; j <= h; ++j)
        if (dp[j] != -1)
            mx = n;

    std::cout << mx << '\n';
    return 0;
}
