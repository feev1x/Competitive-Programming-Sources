/**
 *    author:  feev1x
 *    created: 11.10.2025 18:15:11
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
        int n, m, k; std::cin >> n >> m >> k;

        std::string s; std::cin >> s;

        s = " " + s;

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
        }

        std::vector dp(n + 1, std::vector(k + 1, std::array<bool, 2>{}));
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                dp[i][j][0] = true, dp[i][j][1] = false;

        for (int i = 1; i <= n; ++i)
            dp[i][0][0] = s[i] == 'B';


        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= n; ++i)
                for (auto to: g[i])
                    if (dp[to][j - 1][0])
                        dp[i][j][1] = true;

            for (int i = 1; i <= n; ++i)
                for (auto to: g[i])
                    if (!dp[to][j][1])
                        dp[i][j][0] = false;
        }

        std::cout << (dp[1][k][0] ? "Bob" : "Alice") << '\n';
    }
    return 0;
}
