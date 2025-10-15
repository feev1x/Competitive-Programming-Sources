/**
 *    author:  feev1x
 *    created: 10.10.2025 10:25:35
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
        int n, m, l, u; std::cin >> n >> m >> l >> u;

        std::string s, t; std::cin >> s >> t;
        
        int res = 0, dis = u - l, pw = 0;

        for (pw = 0; pw < 15; ++pw)
            if ((dis >> pw) == 0)
                break;

        if (!pw)
            pw = 1;

        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        std::vector<std::vector<int>> left(n, std::vector<int>(m));
        std::vector<std::vector<int>> up(n, std::vector<int>(m));

        std::vector<std::deque<int>> U(m);
        for (int i = 0; i < n; ++i) {
            std::deque<int> L;

            for (int j = 0; j < m; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1;

                    if (l <= i && l <= j)
                        dp[i][j] = std::max(dp[i][j], up[i - l][j - l] + 1);

                    res = std::max(res, dp[i][j]);
                }

                while (L.size() && j - L.front() > dis)
                    L.pop_front();

                while (L.size() && dp[i][L.back()] <= dp[i][j])
                    L.pop_back();

                L.emplace_back(j);

                left[i][j] = dp[i][L.front()];
            }

            for (int j = 0; j < m; ++j) {
                while (U[j].size() && i - U[j].front() > dis)
                    U[j].pop_front();

                while (U[j].size() && left[U[j].back()][j] <= left[i][j])
                    U[j].pop_back();

                U[j].emplace_back(i);

                up[i][j] = left[U[j].front()][j];
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
