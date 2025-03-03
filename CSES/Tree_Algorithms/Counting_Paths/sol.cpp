/**
 *    author:  feev1x
 *    created: 26.02.2025 17:20:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> tin(n + 1), tout(n + 1), dep(n + 1), ans(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::array<int, 18>> anc(n + 1);
    for (int i = 2; i <= n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    tout[0] = 5 * n;

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = _t++;
        dep[v] = dep[p] + 1;
        anc[v][0] = p;

        for (int j = 1; j < 18; ++j) {
            anc[v][j] = anc[anc[v][j - 1]][j - 1];
        }

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }

        tout[v] = _t;
    };

    Dfs(Dfs, 1, 0);

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
            return u;
        }

        for (int i = 17; i >= 0; --i) {
            if (tin[anc[u][i]] > tin[v] || tout[v] > tout[anc[u][i]]) {
                u = anc[u][i];
            }
        }

        return anc[u][0];
    };

    while (m--) {
        int u, v; std::cin >> u >> v;

        ans[u]++;
        ans[v]++;

        int lca = Lca(u, v);

        ans[lca]--;
        ans[anc[lca][0]]--;
    }

    auto Dfs1 = [&](auto &&self, int v, int p) -> void {
        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            ans[v] += ans[to];
        }
    };

    Dfs1(Dfs1, 1, 1);

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
