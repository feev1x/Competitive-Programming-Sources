/**
 *    author:  feev1x
 *    created: 02.05.2025 15:04:20
**/
#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 20, INF = 1e18;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, r, m; std::cin >> n >> r >> m;

    std::vector<int> p(n + 1), d(n + 1), tin(n + 1), tout(n + 1), sz(n + 1), up(n + 1);
    std::vector<std::vector<int>> g(n + 1), pref(n + 1);
    std::vector<std::array<int, N>> anc(n + 1);
    std::vector<std::vector<std::pair<int, int>>> dep(n + 1);
    p[1] = 1;

    for (int i = 2; i <= n; ++i) {
        std::cin >> p[i];

        g[i].emplace_back(p[i]);
        g[p[i]].emplace_back(i);
    }

    tout[0] = INF;

    int _t = 1;
    auto Dfs = [&](auto &&self, int v) -> void {
        sz[v] = 1;
        tin[v] = _t++;
        d[v] = d[p[v]] + 1;
        anc[v][0] = p[v];
        dep[d[v]].emplace_back(tin[v], v);

        for (int i = 1; i < N; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }

        if (d[v] - 1 >= (m + 1) / 2) {
            int u = v;

            for (int i = 0; i < N; ++i) {
                if (((m + 1) / 2) >> i & 1) {
                    u = anc[u][i];
                }
            }

            up[v] = u;
        }

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            self(self, to);

            sz[v] += sz[to];
        }

        tout[v] = _t++;
    };

    Dfs(Dfs, 1);

    for (int dp = 1; dp <= n; ++dp) {
        int sum = 0;

        for (auto [tn, u]: dep[dp]) {
            sum += sz[u];

            pref[dp].emplace_back(sum);
        }
    }

    for (int v = 1; v <= n; ++v) {
        int64_t res = (n - sz[v]) * (n - sz[v] - 1) / 2;

        if (d[v] + r + 1 <= n) {
            int left = std::lower_bound(dep[d[v] + r + 1].begin(), dep[d[v] + r + 1].end(), std::make_pair(tin[v], int(0))) - dep[d[v] + r + 1].begin();
            int right = std::upper_bound(dep[d[v] + r + 1].begin(), dep[d[v] + r + 1].end(), std::make_pair(tout[v], INF)) - dep[d[v] + r + 1].begin();
            
            for (int i = left; i < right; ++i) {
                int u = dep[d[v] + r + 1][i].second;

                if (m > r) {
                    res += sz[u] * (n - sz[v]);
                }

                res += sz[u] * (sz[u] - 1) / 2;
            }


            int vl = d[v] + r + 1;
            for (int i = left; i + 1 < right; ++i) {
                int lf = i + 1, rt = right - 1, ans = -1;
                
                while (lf <= rt) {
                    int md = lf + rt >> 1;

                    if (tin[up[dep[vl][i].second]] <= tin[dep[vl][md].second] && tout[dep[vl][md].second] <= tout[up[dep[vl][i].second]]) {
                        lf = md + 1;
                        ans = md;
                    } else {
                        rt = md - 1;

                    }
                }

                if (ans != -1) {
                    res += (pref[vl][ans] - pref[vl][i]) * sz[dep[vl][i].second];
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
