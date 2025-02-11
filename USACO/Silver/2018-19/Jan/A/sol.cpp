/**
 *    author:  feev1x
 *    created: 10.02.2025 13:31:21
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("planting.in", "r", stdin);
    std::freopen("planting.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    int res = 0;
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);

        res = std::max(res, (int)g[u].size());
        res = std::max(res, (int)g[v].size());
    }

    std::cout << res + 1 << '\n';
    return 0;
}
