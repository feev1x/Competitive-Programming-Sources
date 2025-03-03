/**
 *    author:  feev1x
 *    created: 28.02.2025 21:51:09
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, st, en; std::cin >> n >> st >> en;

        std::vector<int> res;
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        auto Dfs = [&](auto &&self, int v, int p) -> void {
            for (auto to: g[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);
            }

            res.emplace_back(v);
        };

        Dfs(Dfs, en, -1);

        for (auto u: res) {
            std::cout << u << ' ';
        }

        std::cout << '\n';
    }
    return 0;
}
