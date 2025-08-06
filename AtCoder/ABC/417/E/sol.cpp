/**
 *    author:  feev1x
 *    created: 02.08.2025 18:46:13
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
        int n, m, x, y; std::cin >> n >> m >> x >> y;

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        for (int i = 1; i <= n; ++i)
            std::sort(g[i].begin(), g[i].end());

        std::vector<bool> used(n + 1);

        std::vector<int> ans;

        bool flag = false;
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            ans.emplace_back(v);

            if (v == y) {
                for (auto u: ans)
                    std::cout << u << ' ';

                std::cout << '\n';

                flag = true;

                return;
            }

            for (auto to: g[v]) {
                if (used[to])
                    continue;

                self(self, to);

                if (flag)
                    return;
            }

            ans.pop_back();
        };

        Dfs(Dfs, x);
    }
    return 0;
}
