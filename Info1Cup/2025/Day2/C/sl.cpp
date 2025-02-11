/**
 *    author:  feev1x
 *    created: 09.02.2025 17:49:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::array<int, 18>> anc(n + 1);
    std::vector<int> dep(n + 1), tin(n + 1), tout(n + 1), sz(n + 1, 1);

    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    tin[0] = -1, tout[0] = n * 10000;

    int tm = 0;
    std::function<void(int, int)> Dfs = [&](int v, int p) -> void {
        anc[v][0] = p;
        dep[v] = dep[p] + 1;
        tin[v] = ++tm;

        for (int i = 1; i < 18; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }


        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            Dfs(to, v);

            sz[v] += sz[to];
        }
        
        tout[v] = ++tm;
    };

    Dfs(1, 0);

    std::function<int(int, int)> Lca = [&](int u, int v) {
        for (int i = 17; i >= 0; --i) {
            int p = anc[u][i];

            if (!(tin[p] <= tin[v] && tout[v] <= tout[p])) {
                u = p;
            }
        }

        return anc[u][0];
    };


    std::function<int(int, int)> Lift = [&](int u, int v) {
        for (int i = 17; i >= 0; --i) {
            int p = anc[u][i];

            if (v >> i & 1) {
                u = p;
            }
        }

        return u;
    };

    int q; std::cin >> q;
    while (q--) {
        int m; std::cin >> m;
        
        int res = n;
        std::vector<int> a(m);
        for (auto &u: a) {
            std::cin >> u;
        }

        if (m == 1) {
            std::cout << n << '\n';

            continue;
        }

        assert(a[0] != a[1]);

        int lca = Lca(a[0], a[1]);

        int dis = dep[a[0]] + dep[a[1]] - 2 * dep[lca];


        if (dis & 1) {
            std::cout << n << '\n';

            continue;
        }
        
        int u = Lift(a[0], dis >> 1), v = Lift(a[1], dis >> 1);

        if (tin[u] < tin[lca] && tout[lca] < tout[u]) {
            int is = v, sum = 1;
            v = Lift(a[1], dis / 2 - 1);

            res = 0;
            for (auto to: g[is]) {
                if (to == anc[is][0]) {
                    continue;
                }

                if (to == v) {
                    continue;
                }

                sum += sz[to];
            }

            res = n - sum;
        } else {
            if (dep[a[0]] == dep[a[1]]) {
                u = Lift(a[0], dis / 2 - 1), v = Lift(a[1], dis / 2 - 1);

                res = sz[u] + sz[v];
            } else {
                int is = u, sum = 1;
                u = Lift(a[0], dis / 2 - 1);

                res = 0;
                for (auto to: g[is]) {
                    if (to == anc[is][0]) {
                        continue;
                    }

                    if (to == u) {
                        continue;
                    }

                    sum += sz[to];
                }

                res = n - sum;
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
