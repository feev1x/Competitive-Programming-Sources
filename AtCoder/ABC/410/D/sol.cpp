/**
 *    author:  feev1x
 *    created: 16.08.2025 13:25:22
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
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    std::queue<std::pair<int, int>> q;
    std::vector dp(n + 1, std::vector<bool>(1 << 10));

    dp[1][0] = true;
    q.emplace(1, 0);
    while (q.size()) {
        auto [v, mask] = q.front();

        q.pop();
        for (auto [to, w]: g[v]) {
            if (!dp[to][mask ^ w]) {
                dp[to][mask ^ w] = true;

                q.emplace(to, mask ^ w);
            }
        }
    }

    int res = -1;
    for (int i = 0; i < 1 << 10; ++i)
        if (dp[n][i]) {
            res = i;
            break;
        }

    std::cout << res << '\n';
    return 0;
}
