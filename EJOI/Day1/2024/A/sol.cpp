/**
 *    author:  feev1x
 *    created: 25.04.2025 09:10:27
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> idx(n + 1), p(n + 1), tin(n + 1, -INF), tout(n + 1, INF);
    std::vector<int64_t> ans1(n + 1), cst(n + 1), up(n + 1);
    std::vector<std::vector<int>> g(n + 1), adj(n + 1);
    std::vector<std::vector<int64_t>> pref(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::map<std::pair<int, int>, int64_t> cost;
    for (int i = 1; i <= k; ++i) {
        int u, v, c; std::cin >> u >> v >> c;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);

        cost[{u, v}] = (cost[{v, u}] += c);
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        int id = 0;
        int64_t mx = 0, mx2 = 0;

        tin[v] = _t++;
        for (auto to: g[v]) {
            if (cost[{v, to}] > mx) {
                mx2 = mx;
                mx = cost[{v, to}];
            } else if (cost[{v, to}] > mx2) {
                mx2 = cost[{v, to}];
            }

            if (to == p[v]) {
                continue;
            }

            p[to] = v;
            idx[to] = id++;

            self(self, to);

            cst[v] += cst[to];
            up[v] += cst[to];
        }

        for (auto nx: adj[v]) {
            if (tin[v] <= tin[nx] && tout[nx] <= tout[v]) {
                cst[v] += cost[{nx, v}];
            }
        }

        ans1[v] = mx + mx2;

        tout[v] = _t++;
    };

    Dfs(Dfs, 1);

    for (int i = 1; i <= n; ++i) {
        adj[i].emplace_back(0);

        std::sort(adj[i].begin(), adj[i].end(), [&](int u, int v) {
            return tin[u] < tin[v];
        });

        int64_t pfx = 0;
        for (int j = 0; j < adj[i].size(); ++j) {
            pfx += cost[{adj[i][j], i}];

            pref[i].emplace_back(pfx);
        }
    }

    int64_t val = 0;
    auto Up = [&](auto &&self, int v) -> void {
        up[v] = val;
        val += cst[v];

        for (auto nx: adj[v]) {
            if (!(tin[v] <= tin[nx] && tout[nx] <= tout[v])) {
                up[v] += cost[{nx, v}];
            }
        }

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            val -= cst[to];

            self(self, to);

            val += cst[to];
        }
    };

    Up(Up, 1);

    for (auto [key, c]: cost) {
        auto [u, v] = key;

        if (!u || !v || !c) {
            continue;
        }

        if (p[u] == p[v]) {
            int l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[v] <= tin[adj[p[v]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[v] >= tin[adj[p[v]][m]]) {
                    l = m + 1;
                    ans = m;
                } else {
                    r = m - 1;
                }
            }

            int64_t pfr = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[u] <= tin[adj[p[v]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl1 = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[u] >= tin[adj[p[v]][m]]) {
                    l = m + 1;
                    ans = m;
                } else {
                    r = m - 1;
                }
            }

            int64_t pfr1 = pref[p[v]][ans];

            ans1[p[v]] = std::max(ans1[p[v]], cst[u] + cst[v] + c + pfr - pfl + pfr1 - pfl1);
        } else if (p[p[u]] == v) {
            int l = 0, r = adj[p[u]].empty() ? 0 : adj[p[u]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[u] <= tin[adj[p[u]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl1 = pref[p[u]][ans];

            l = 0, r = adj[p[u]].empty() ? 0 : adj[p[u]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[u] >= tin[adj[p[u]][m]]) {
                    l = m + 1;
                    ans = m;
                } else {
                    r = m - 1;
                }
            }

            int64_t pfr1 = pref[p[u]][ans];

            l = 0, r = adj[p[u]].empty() ? 0 : adj[p[u]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[v] <= tin[adj[p[u]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl = pref[p[u]][ans];

            l = 0, r = adj[p[u]].empty() ? 0 : adj[p[u]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[v] > tin[adj[p[u]][m]]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                    ans = m;
                }
            }

            int64_t pfr = pref[p[u]][ans];

            ans1[p[u]] = std::max(ans1[p[u]], cst[u] + pfr1 - pfl1 + c + pfl - pfr + pref[p[u]].back());
        } else if (p[p[v]] == u) {
            int l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[v] <= tin[adj[p[v]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl1 = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[v] >= tin[adj[p[v]][m]]) {
                    l = m + 1;
                    ans = m;
                } else {
                    r = m - 1;
                }
            }

            int64_t pfr1 = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tin[u] <= tin[adj[p[v]][m]]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                    ans = m;
                }
            }

            int64_t pfl = pref[p[v]][ans];

            l = 0, r = adj[p[v]].empty() ? 0 : adj[p[v]].size() - 1, ans = 0;
            while (l <= r) {
                int m = l + r >> 1;

                if (tout[u] > tin[adj[p[v]][m]]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                    ans = m;
                }
            }

            int64_t pfr = pref[p[v]][ans];

            ans1[p[v]] = std::max(ans1[p[v]], cst[v] + pfr1 - pfl1 + c + pfl - pfr + pref[p[v]].back());
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << ans1[i] << " \n"[i == n];
    }
    return 0;
}
