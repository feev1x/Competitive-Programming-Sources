/**
 *    author:  feev1x
 *    created: 27.02.2025 11:07:58
**/
#include <bits/stdc++.h>

using graph = std::vector<std::vector<int>>;

struct Centroid {
    std::vector<int> sz;
    graph g;
    int n;

    Centroid(graph _g) : g(_g) {
        sz.resize(g.size());
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline int get(int v, int p) {
        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            if (sz[to] * 2 > n) {
                return get(to, v);
            }
        }

        return v;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    graph g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Centroid cen(g);
    
    cen.dfs(1, 1);
    
    cen.n = cen.sz[1];

    std::cout << cen.get(1, 1) << '\n';
    return 0;
}
