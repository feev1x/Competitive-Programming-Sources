/**
 *    author:  feev1x
 *    created: 05.07.2025 15:35:46
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> x(m + 1), tin(n + 1), tout(n + 1), d(n + 1);
    std::vector<int64_t> cst(n + 1);
    std::vector<int> ve(m + 1);
    std::vector<std::array<int, 20>> anc(n + 1, std::array<int, 20>{});
    std::vector<std::array<int64_t, 20>> sum(n + 1, std::array<int, 20>{});
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        d[v] = d[p] + 1;
        anc[v][0] = p;

        for (int i = 1; i < 20; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            sum[v][i] = sum[anc[v][i - 1]][i - 1] + sum[v][i - 1];
        }

        for (auto [to, w]: g[v]) {
            if (to == p) {
                continue;
            }

            cst[to] = cst[v] + w;
            sum[to][0] = w;
            self(self, to, v);
        }

        tout[v] = ++_t;
    };

    Dfs(Dfs, 1, 1);

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
            return u;
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];
            
            if (!(tin[nx] <= tin[v] && tout[v] <= tout[nx])) {
                u = nx;
            }
        }

        return anc[u][0];
    };

    int lca = -1;
    for (int i = 1; i <= m; ++i) {
        std::cin >> x[i] >> ve[i];

        if (lca == -1) {
            lca = x[i];
        }

        lca = Lca(lca, x[i]);
    }

    assert(lca != -1);

    int64_t l = 0, r = 3e11, ans = -1;
    while (l <= r) {
        int64_t _m = l + r >> 1;

        std::vector<std::pair<int, int>> ar;
        ar.emplace_back(lca, 0);
        for (int i = 1; i <= m; ++i) {
            int u = x[i];

            int64_t sm = cst[u] - cst[lca];

            if (sm > _m * ve[i]) {
                sm = 0;

                int v = x[i];
                for (int j = 19; j >= 0; --j) {
                    if (anc[v][j] && sum[v][j] + sm <= _m * ve[i]) {
                        sm += sum[v][j];
                        v = anc[v][j];
                    }
                }

                int cl = _m * ve[i] - sm;

                assert(cl <= sum[v][0]);

                ar.emplace_back(v, cl);
            }
        }

        auto [v, cl] = ar.back();

        for (auto [u, lc]: ar) {
            if (d[u] > d[v] || d[u] == d[v] && cl > lc) {
                v = u;
                cl = lc;
            }
        }

        bool flag = true;
        for (int i = 1; i <= m; ++i) {
            int u = x[i];

            int lc = Lca(u, v);

            int ds = cst[u] + cst[v] - cst[lc] * 2;

            if (lc == v) {
                ds += cl;
            } else {
                ds -= cl;
            }

            if (ds > _m * ve[i]) {
                flag = false;
            }
        }

        if (flag) {
            r = _m - 1, ans = _m;
        } else {
            l = _m + 1;
        }
    }

    assert(ans != -1);


    std::cout << ans << '\n';
    return 0;
}
