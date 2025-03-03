/**
 *    author:  feev1x
 *    created: 25.02.2025 14:18:17
**/
#include <bits/stdc++.h>

using graph = std::vector<std::vector<int>>;

struct Centroid {
    std::vector<int> sz, val;
    std::vector<bool> del;
    graph g;
    int n, rank;

    Centroid(graph _g) : g(_g), rank(0) {
        sz.resize(g.size());
        val.resize(g.size());
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

    inline void calc(int v) {
        dfs(v, v);

        n = sz[v], v = get(v, v);

        val[v] = rank++;
        del[v] = true;
        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            calc(to);
        }

        rank--;
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
    
    cen.calc(1);

    auto res = cen.val;

    if (*std::max_element(res.begin(), res.end()) < 26) {
        for (int i = 1; i <= n; ++i) {
            std::cout << char(res[i] + 'A') << " \n"[i == n];
        }
    } else {
        std::cout << "Impossible!\n";
    }
    return 0;
}
