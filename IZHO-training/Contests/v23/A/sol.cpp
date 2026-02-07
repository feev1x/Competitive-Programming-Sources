#include <bits/stdc++.h>

#define int int64_t

constexpr int INF = 1e18;

inline void chmax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k; std::cin >> n >> m >> k;

    int64_t MXTEMP = 0;
    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];

        MXTEMP = std::max(MXTEMP, w[i]);
    }

    std::vector<int> d(n + 1);
    std::vector<std::vector<bool>> g(n + 1, std::vector<bool>(n + 1));
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        MXTEMP = std::max(MXTEMP, w[u] + w[v]);
        d[u]++, d[v]++;
        g[u][v] = g[v][u] = true;
    }

    if (k == 1) {
        std::cout << MXTEMP << '\n';
        exit(0);
    }

    int64_t res = 0;
    std::set<std::pair<int, int>> st;
    for (int i = 1; i <= n; ++i) {
        st.emplace(d[i], i);
    }

    auto Remove = [&](int u, int v) {
        g[u][v] = g[v][u] = false;
        d[u]--, d[v]--;
    };

    while (st.size()) {
        int v = st.begin()->second;

        st.erase(st.begin());

        int nw = 0;
        std::vector<int> pos(n + 1, -1);
        std::vector<int> a;
        for (int to = 1; to <= n; ++to) {
            if (g[v][to]) {
                pos[to] = nw++;
                a.emplace_back(to);
            }
        }

        std::vector<int> adj(nw);
        for (int i = 0; i < nw; ++i) {
            int u = a[i];

            for (int to = 1; to <= n; ++to) {
                if (pos[to] != -1 && g[u][to]) {
                    adj[i] |= 1 << pos[to];
                }
            }
        }

        int nl = nw / 2, nr = nw - nl;
        std::vector<int> dp(1 << nl, -INF), dp2(1 << nr, -INF);

        dp[0] = 0;
        for (int mask = 0; mask < 1 << nl; ++mask) {
            if (dp[mask] == -INF) {
                continue;
            }

            for (int i = 0; i < nl; ++i) {
                if (mask >> i & 1) {
                    continue;
                }

                if ((adj[i] & mask) == mask) {
                    chmax(dp[mask | (1 << i)], dp[mask] + w[a[i]]);
                }
            }
        }

        dp2[0] = 0;
        for (int mask = 0; mask < 1 << nr; ++mask) {
            if (dp2[mask] == -INF) {
                continue;
            }

            for (int i = 0; i < nr; ++i) {
                if (mask >> i & 1) {
                    continue;
                }

                if (((adj[i + nl] >> nl) & mask) == mask) {
                    chmax(dp2[mask | (1 << i)], dp2[mask] + w[a[i + nl]]);
                }
            }
        }

        for (int i = 0; i < nr; ++i) {
            for (int mask = 0; mask < 1 << nr; ++mask) {
                if (mask >> i & 1) {
                    continue;
                }

                chmax(dp2[mask | (1 << i)], dp2[mask]);
            }
        }

        for (int mask = 0; mask < 1 << nl; ++mask) {
            int nmask = 0;

            for (int i = 0; i < nr; ++i) {
                if ((adj[i + nl] & mask) == mask) {
                    nmask |= 1 << i;
                }
            }

            chmax(res, dp[mask] + dp2[nmask] + w[v]);
        }

        for (auto u: a) {
            Remove(v, u);
        }
    }

    std::cout << res << '\n';
    return 0;
}
