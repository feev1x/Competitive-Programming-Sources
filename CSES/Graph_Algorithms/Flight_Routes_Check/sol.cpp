/**
 *    author:  feev1x
 *    created: 04.03.2025 02:18:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1), adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<bool> used(n + 1);
    {
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: g[v]) {
                if (used[to]) {
                    continue;
                }

                self(self, to);
            }
        };

        Dfs(Dfs, 1);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            std::cout << "NO\n1 " << i << '\n';

            exit(0);
        }

        used[i] = false;
    }
    
    {
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: adj[v]) {
                if (used[to]) {
                    continue;
                }

                self(self, to);
            }
        };

        Dfs(Dfs, 1);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            std::cout << "NO\n" << i << " 1\n";

            exit(0);
        }
    }

    std::cout << "YES\n";
    return 0;
}
