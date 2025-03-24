/**
 *    author:  feev1x
 *    created: 03.03.2025 17:39:03
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::array<int, 3>> edges;
    std::vector<bool> used(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w; w = -w;

        g[v].emplace_back(u);
        edges.push_back({u, v, w});
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }
    };

    Dfs(Dfs, n);

    std::vector<int64_t> dis(n + 1, INF);
    dis[1] = 0;

    int tt = n - 1;
    while (tt--) {
        for (auto [u, v, w]: edges) {
            if (dis[u] != INF && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;

            }
        }
    }

    for (auto [u, v, w]: edges) {
        if (dis[u] != INF && dis[v] > dis[u] + w) {
            if (used[v]) {
                std::cout << "-1\n";
                
                exit(0);
            }
        }
    }

    std::cout << -dis[n] << '\n';
    return 0;
}
