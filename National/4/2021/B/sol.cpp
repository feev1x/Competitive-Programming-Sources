/**
 *    author:  feev1x
 *    created: 05.03.2025 09:47:04
**/
#include <bits/stdc++.h>

using wgraph = std::vector<std::vector<std::pair<int, int>>>;

struct Centroid {
    std::vector<int> sz;
    std::vector<bool> del;
    wgraph g;
    int n, k;

    Centroid(wgraph _g, int _k): g(_g), k(_k) {
        sz.resize(g.size());
        del.resize(g.size());
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline int get(int v, int p) {
        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            if (sz[to] * 2 > n) {
                return get(to, v);
            }
        }

        return v;
    }

    inline int64_t calc(int v) {
        dfs(v, v);

        n = sz[v], v = get(v, v);


    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    wgraph g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; std::cin >> u >> v >> w;
        
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    Centroid cen(g, k);

    std::cout << cen.calc(1) << '\n';
    return 0;
}
