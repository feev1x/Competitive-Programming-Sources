/**
 *    author:  feev1x
 *    created: 06.04.2025 11:26:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> dep(n + 1);
    std::vector<std::vector<int>> g(n + 1), ver(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        g[u].emplace_back(i);
        g[i].emplace_back(u);
    }

    dep[0] = -2;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        dep[v] = dep[p] + 1;

        if (dep[v] >= 0) {
            ver[dep[v]].emplace_back(v);
        }

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }
    };

    Dfs(Dfs, 0, 0);

    for (int i = 0; i <= n; ++i) {
        if (i & 1) {
            reverse(ver[i].begin(), ver[i].end());
        }

        for (auto u: ver[i]) {
            std::cout << u << ' ';
        }
    }

    std::cout << '\n';
    return 0;
}
