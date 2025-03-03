/**
 *    author:  feev1x
 *    created: 26.02.2025 17:01:20
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> tin(n + 1), tout(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::array<int, 18>> anc(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> anc[i][0];

        g[anc[i][0]].emplace_back(i);
        g[i].emplace_back(anc[i][0]);
    }

    anc[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 18; ++j) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = _t++;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }

        tout[v] = _t;
    };

    Dfs(Dfs, 1, 1);

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

    while (q--) {
        int u, v; std::cin >> u >> v;

        std::cout << Lca(u, v) << '\n';
    }
    return 0;
}
