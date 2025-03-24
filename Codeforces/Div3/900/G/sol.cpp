/**
 *    author:  feev1x
 *    created: 05.03.2025 17:47:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1), p(n + 1), tin(n + 1), tout(n + 1), dis(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        std::vector<std::vector<int>> g(n + 1);
        std::vector<std::array<int, 30>> pref(n + 1), anc(n + 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 30; ++j) {
                pref[i][j] = anc[i][j] = 0;
            }
        }

        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        
        int _t = 1;
        auto Dfs = [&](auto &&self, int v) -> void {
            anc[v][0] = p[v];
            dis[v] = dis[p[v]] + 1;
            pref[v] = pref[p[v]];
            tin[v] = _t++;

            for (int j = 0; j < 30; ++j) {
                pref[v][j] += a[v] >> j & 1;

                if (j) {
                    anc[v][j] = anc[anc[v][j - 1]][j - 1];
                }
            }

            for (auto to: g[v]) {
                if (to == p[v]) {
                    continue;
                }

                p[to] = v;

                self(self, to);
            }

            tout[v] = _t;
        };

        Dfs(Dfs, 1);

        tout[0] = _t;

        auto Lca = [&](int u, int v) {
            if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
                return u;
            }

            for (int i = 29; i >= 0; --i) {
                int nx = anc[u][i];

                if (tin[nx] > tin[v] || tout[v] > tout[nx]) {
                    u = nx;
                }
            }

            return anc[u][0];
        };

        auto Move = [&](int u, int v, int lca, int cnt) {
            if (dis[u] - dis[lca] >= cnt) {
                for (int i = 0; i < 30; ++i) {
                    if (cnt >> i & 1) {
                        u = anc[u][i];
                    }
                }

                return u;
            }

            cnt -= (dis[u] - dis[lca]);

            cnt = (dis[v] - dis[lca]) - cnt;

            for (int i = 0; i < 30; ++i) {
                if (cnt >> i & 1) {
                    v = anc[v][i];
                }
            }

            return v;
        };

        auto Pref1 = [&](int u, int v, int i) {
            bool res = pref[v][i] - pref[p[u]][i];

            return res;
        };

        auto Pref = [&](int u, int v) {
            int res = 0;

            for (int i = 0; i < 30; ++i) {
                bool mul = pref[v][i] - pref[p[u]][i];

                res |= (1 << i) * mul;
            }

            return res;
        };

        int q; std::cin >> q;
        while (q--) {
            int u, v; std::cin >> u >> v;

            int lca = Lca(u, v), ds = dis[u] + dis[v] - dis[lca] * 2, res = 0;

            for (int i = 0; i < 30; ++i) {
                int l = 0, r = ds, ans = 0;

                while (l <= r) {
                    int m = l + r >> 1;

                    int z = Move(u, v, lca, m), pp;

                    if (m > dis[u] - dis[lca]) {
                        pp = Pref1(lca, u, i) | Pref1(lca, z, i);
                    } else {
                        pp = Pref1(z, u, i);
                    }
                    
                    if (pp) {
                        r = m - 1, ans = m;
                    } else {
                        l = m + 1;
                    }
                }

                int z = Move(u, v, lca, ans), pp;

                if (ans > dis[u] - dis[lca]) {
                    pp = Pref(lca, u) | Pref(lca, z);
                } else {
                    pp = Pref(z, u);
                }

                int _m = ds - ans, _pp; 

                if (_m > dis[v] - dis[lca]) {
                    _pp = Pref(lca, v) | Pref(lca, z);
                } else {
                    _pp = Pref(z, v);
                }

                res = std::max(res, __builtin_popcount(pp) + __builtin_popcount(_pp));
            }

            std::cout << res << " \n"[!q];
        }
    }
    return 0;
}
