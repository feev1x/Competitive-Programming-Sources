/**
 *    author:  feev1x
 *    created: 29.03.2025 18:05:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }
    };

    int res = n;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }
        
        Dfs(Dfs, i);
        res--;
    }

    std::cout << m - res << '\n';
    return 0;
}
