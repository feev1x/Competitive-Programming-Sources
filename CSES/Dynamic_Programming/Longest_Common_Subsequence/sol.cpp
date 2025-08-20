/**
 *    author:  feev1x
 *    created: 19.08.2025 16:19:35
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
    
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (auto &u: a)
        std::cin >> u;

    for (auto &u: b)
        std::cin >> u;

    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (i < n && j < m && a[i] == b[j])
                chmax(dp[i + 1][j + 1], dp[i][j] + 1);
            
            if (i + 1 <= n)
                chmax(dp[i + 1][j], dp[i][j]);

            if (j + 1 <= m)
                chmax(dp[i][j + 1], dp[i][j]);
        }

    int i = n, j = m;
    std::vector<int> res;
    while (dp[i][j]) {
        if (dp[i - 1][j] == dp[i][j])
            i--;
        else if (dp[i][j - 1] == dp[i][j])
            j--;
        else {
            assert(a[i - 1] == b[j - 1] && dp[i - 1][j - 1] == dp[i][j] - 1);

            i--, j--;
            res.emplace_back(a[i]);
        }
    }

    std::reverse(res.begin(), res.end());
    
    std::cout << res.size() << '\n';
    for (auto u: res)
        std::cout << u << ' ';

    std::cout << '\n';
    return 0;
}
