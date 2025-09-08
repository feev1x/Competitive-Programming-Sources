/**
 *    author:  feev1x
 *    created: 07.09.2025 21:58:24
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
        int n, m, q; std::cin >> n >> m >> q;

        std::vector<std::vector<int>> g(n + 1), adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        std::vector<std::array<bool, 2>> dp(n + 1, {true, true});
        std::vector<bool> red(n + 1);
        while (q--) {
            int type, u; std::cin >> type >> u;

            if (type == 1) {
                std::queue<int> q;

                red[u] = true;

                q.emplace(u);
                while (q.size()) {
                    int v = q.front();

                    q.pop();

                    auto st = dp[v];

                    if (!red[v] && g[v].size()) {
                        dp[v][0] = false;
                        dp[v][1] = true;
                        for (auto to: g[v]) {
                            if (dp[to][1])
                                dp[v][0] = true;

                            if (!dp[to][0])
                                dp[v][1] = false;
                        }
                    } else if (red[v])
                        dp[v] = {false, false};
                    else
                        dp[v] = {true, true};


                    if (st == dp[v])
                        continue;

                    for (auto to: adj[v])
                        q.emplace(to);
                }
            } else {
                std::cout << (dp[u][0] ? "YES" : "NO") << '\n';
            }
        }
    }
    return 0;
}
