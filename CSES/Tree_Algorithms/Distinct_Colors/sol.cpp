/**
 *    author:  feev1x
 *    created: 27.02.2025 10:43:27
**/
#include <bits/stdc++.h>
#pragma GCC targe("arch=native")
#pragma GCC optimize("O3,unroll-loops")

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::set<int>> st(n + 1);
    std::vector<int> col(n + 1), ans(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> col[i];

        st[i].emplace(col[i]);
    }

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p) -> void {
        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            if (st[v].size() < st[to].size()) {
                std::swap(st[v], st[to]);
            }

            for (auto u: st[to]) {
                st[v].emplace(u);
            }
        }

        ans[v] = st[v].size();
    };

    Dfs(Dfs, 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
