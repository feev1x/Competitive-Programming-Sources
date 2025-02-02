/**
 *    author:  feev1x
 *    created: 19.01.2025 21:11:15
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1,  1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u);
        v = get(v);
        
        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m1, m2; std::cin >> n >> m1 >> m2;

        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m1; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        Dsu d(n);
        for (int i = 0; i < m2; ++i) {
            int u, v; std::cin >> u >> v;

            d.unite(u, v);
        }

        std::vector<bool> used(n + 1), comp(n + 1);
        int res = 0;
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: g[v]) {
                if (d.get(to) != d.get(v)) {
                    res++;
                    continue;
                }

                if (used[to]) {
                    continue;
                }

                self(self, to);
            }
        };

        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                continue;
            }

            Dfs(Dfs, i);

            res += 2 * comp[d.get(i)];
            comp[d.get(i)] = true;
        }

        std::cout << res / 2 << '\n';
    }
    return 0;
}
