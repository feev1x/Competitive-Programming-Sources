/**
 *    author:  feev1x
 *    created: 30.06.2025 22:52:47
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        std::vector<int> sz(n + 1);
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            if (g[v].size() == 1 && v != 1) {
                sz[v] = 1;
            }

            for (auto to: g[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);
                sz[v] += sz[to];
            }
        };

        Dfs(Dfs, 1, 1);

        int q; std::cin >> q;
        while (q--) {
            int x, y; std::cin >> x >> y;

            std::cout << (int64_t)sz[x] * sz[y] << '\n';
        }
    }
    return 0;
}
