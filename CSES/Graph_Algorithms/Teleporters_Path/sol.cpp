/**
 *    author:  feev1x
 *    created: 04.03.2025 13:57:12
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> in_d(n + 1), out_d(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        in_d[v]++;
        out_d[u]++;
    }

    for (int i = 2; i < n; ++i) {
        if (in_d[i] != out_d[i]) {
            std::cout << "IMPOSSIBLE\n";

            exit(0);
        }
    }

    int e1 = 1, e2 = n;

    if (in_d[e1] > out_d[e1]) {
        std::swap(e1, e2);
    }

    if (!(out_d[e1] - in_d[e1] == 1 && in_d[e2] - out_d[e2] == 1)) {
        std::cout << "IMPOSSIBLE\n";

        exit(0);
    }

    g[e2].emplace_back(e1);

    std::stack<int> stk;
    std::vector<int> path;

    stk.emplace(1);
    while (stk.size()) {
        int v = stk.top();

        if (g[v].empty()) {
            path.emplace_back(v);

            stk.pop();
        } else {
            stk.emplace(g[v].back());

            g[v].pop_back();
        }
    }

    if (path.size() < m + 1) {
        std::cout << "IMPOSSIBLE\n";

        exit(0);
    }

    std::reverse(path.begin(), path.end());

    for (int i = 0; i <= m; ++i) {
        if (path[i] == n && path[i + 1] == 1) {
            std::vector<int> tmp;

            for (int j = i + 1; j <= m; ++j) {
                tmp.emplace_back(path[j]);
            }

            for (int j = 0; j <= i; ++j) {
                tmp.emplace_back(path[j]);
            }

            path = tmp;

            break;
        }
    }

    for (int i = 0; i <= m; ++i) {
        std::cout << path[i] << " \n"[i == m];
    }
    return 0;
}
