/**
 *    author:  feev1x
 *    created: 03.03.2025 21:23:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> pos(n + 1), ord;
    std::vector<bool> used(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }

        ord.emplace_back(v);
        pos[v] = ord.size();
    };

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        Dfs(Dfs, i);
    }

    for (int i = 1; i <= n; ++i) {
        for (auto to: g[i]) {
            if (pos[to] >= pos[i]) {
                std::cout << "IMPOSSIBLE\n";

                exit(0);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ord[i] << " \n"[i == n - 1];
    }
    return 0;
}
