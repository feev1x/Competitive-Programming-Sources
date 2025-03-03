/**
 *    author:  feev1x
 *    created: 26.02.2025 16:30:10
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> sz(n + 1);
    std::vector<int64_t> sum(n + 1), ans(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
         int u, v; std::cin >> u >> v;

         g[u].emplace_back(v);
         g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p) -> void {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            sz[v] += sz[to];
            sum[v] += sum[to] + sz[to];
        }
    };

    Dfs(Dfs, 1, 0);

    auto Dfs1 = [&](auto &&self, int v, int p, int64_t sm) -> void {
        ans[v] = sum[v] + sm;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v, sm + sum[v] - sum[to] + n - sz[to] * 2);
        }
    };

    Dfs1(Dfs1, 1, 0, 0ll);

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
