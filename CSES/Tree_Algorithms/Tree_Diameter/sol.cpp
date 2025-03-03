/**
 *    author:  feev1x
 *    created: 26.02.2025 16:15:57
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> dep(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p) -> void {
        dep[v] = dep[p] + 1;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }
    };

    Dfs(Dfs, 1, 1);

    int v = std::max_element(dep.begin(), dep.end()) - dep.begin();

    dep[0] = -1;
    Dfs(Dfs, v, 0);

    std::cout << *std::max_element(dep.begin(), dep.end()) << '\n';
    return 0;
}
