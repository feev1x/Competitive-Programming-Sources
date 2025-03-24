/**
 *    author:  feev1x
 *    created: 04.03.2025 02:33:21
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1), r_g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        r_g[v].emplace_back(u);
    }

    std::vector<int> ord, comp(n + 1);
    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }

        ord.emplace_back(v);
    };

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        Dfs(Dfs, i);
    }

    std::reverse(ord.begin(), ord.end());

    int cmp = 0;
    std::fill(used.begin(), used.end(), 0);
    auto Scc = [&](auto &&self, int v) -> void {
        used[v] = true;
        comp[v] = cmp;

        for (auto to: r_g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }
    };

    for (auto v: ord) {
        if (used[v]) {
            continue;
        }

        cmp++;
        Scc(Scc, v);
    }

    std::cout << cmp << '\n';
    for (int i = 1; i <= n; ++i) {
        std::cout << comp[i] << " \n"[i == n];
    }
    return 0;
}
