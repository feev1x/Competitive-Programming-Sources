/**
 *    author:  feev1x
 *    created: 04.03.2025 05:12:50
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::set<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace(v);
        g[v].emplace(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (g[i].size() & 1) {
            std::cout << "IMPOSSIBLE\n";

            exit(0);
        }
    }

    std::stack<int> stk;
    std::vector<int> res;

    stk.emplace(1);
    while (stk.size()) {
        int v = stk.top();

        if (g[v].empty()) {
            res.emplace_back(v);
            stk.pop();
        } else {
            stk.emplace(*g[v].begin());

            g[*g[v].begin()].erase(v);
            g[v].erase(g[v].begin());
        }
    }

    if (res.size() < m + 1) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        for (auto u: res) {
            std::cout << u << ' ';
        }

        std::cout << '\n';
    }
    return 0;
}
