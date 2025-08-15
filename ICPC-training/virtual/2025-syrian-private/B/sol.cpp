/**
 *    author:  feev1x
 *    created: 13.08.2025 16:30:32
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

        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i <= n; ++i) 
            std::cin >> a[i];

        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        std::vector<std::array<std::array<bool, 2>, 2>> dp(n + 1);

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 2; ++j)
                dp[i][j][0] = dp[i][j][1] = false;

        auto Dfs = [&](auto &&self, int v, int p) -> void {
            std::array<std::array<int, 2>, 2> cnt;

            for (int i = 0; i < 2; ++i)
                cnt[i][0] = cnt[i][1] = 0;

            int chi = 0;
            for (auto to: g[v]) {
                if (to == p)
                    continue;

                self(self, to, v);

                chi++;
                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 2; ++j)
                        cnt[i][j] += dp[to][i][j];
            }

            // 0 0
            {
                int cn = cnt[1][1];
                bool ch = a[v], flag = true;
                for (auto to: g[v]) {
                    if (to == p || dp[to][1][0])
                        continue;

                    if (dp[to][1][1]) {
                        ch = !ch;
                        cn--;
                        continue;
                    }

                    flag = false;
                    break;
                }

                if (ch && !cn)
                    flag = false;

                dp[v][0][0] = flag;
            }

            // 0 1
            {
                int cn = cnt[0][1];
                bool ch = a[v], flag = true;
                for (auto to: g[v]) {
                    if (to == p || dp[to][0][0])
                        continue;

                    if (dp[to][0][1]) {
                        ch = !ch;
                        cn--;
                        continue;
                    }

                    flag = false;
                    break;
                }

                if (!ch && !cn)
                    flag = false;

                dp[v][0][1] = flag;
            }

            // 1 0
            {
                int cn = cnt[1][1];
                bool ch = a[v], flag = true;
                for (auto to: g[v]) {
                    if (to == p || dp[to][1][0])
                        continue;

                    if (dp[to][1][1]) {
                        ch = !ch;
                        cn--;
                        continue;
                    }

                    flag = false;
                    break;
                }

                if (!ch && !cn)
                    flag = false;

                dp[v][1][0] = flag;
            }

            // 1 1
            {
                int cn = cnt[0][1];
                bool ch = a[v], flag = true;
                for (auto to: g[v]) {
                    if (to == p || dp[to][0][0])
                        continue;

                    if (dp[to][0][1]) {
                        ch = !ch;
                        cn--;
                        continue;
                    }

                    flag = false;
                    break;
                }

                if (ch && !cn)
                    flag = false;

                dp[v][1][1] = flag;
            }
        };

        Dfs(Dfs, 1, 1);

        std::cout << (dp[1][1][0] || dp[1][1][1] ? "YES\n" : "NO\n");
    }
    return 0;
}
