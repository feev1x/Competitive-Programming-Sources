/**
 *    author:  feev1x
 *    created: 02.07.2025 12:20:52
**/
#include <bits/stdc++.h>

#define int int64_t

constexpr int64_t INF = 1e18;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n, m, p, gr; std::cin >> n >> m >> p >> gr;

    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];
    }

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, s; std::cin >> u >> v >> s;

        g[u].emplace_back(v, s);
    }

    if (gr == 1) {
        std::vector<int64_t> dis(n + 1, INF);
        dis[1] = 0;
        
        std::set<std::pair<int64_t, int>> st;
        st.emplace(0, 1);
        while (st.size()) {
            int v = st.begin()->second;

            st.erase(st.begin());
            for (auto [to, s]: g[v]) {
                if (dis[to] > dis[v] + s) {
                    st.erase({dis[to], to});
                    dis[to] = dis[v] + s;
                    st.emplace(dis[to], to);
                }
            }
        }

        if (dis[n] == INF) {
            std::cout << "-1\n";

            exit(0);
        }

        std::cout << std::max((int64_t)0, dis[n] - p) << '\n';
    } else if (gr == 2) {
        int mx = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            mx = std::max(mx, w[i]);

            assert(g[i].size() == 1);
            int cost = g[i][0].second;

            if (p >= cost) {
                p -= cost;
            } else {
                res += ((cost - p) + mx - 1) / mx;
                p += (((cost - p) + mx - 1) / mx) * mx;
                p -= cost;
            }
        }

        std::cout << res << '\n';
    } else {
        std::vector<std::vector<std::pair<int64_t, int64_t>>> dis(n + 1, std::vector<std::pair<int64_t, int64_t>>(n + 1, {INF, -INF}));
        dis[1][1] = {0, p};
        
        std::set<std::array<int64_t, 4>> st;
        st.insert({0, -p, 1, 1});
        while (st.size()) {
            auto [_, __, v, mx] = *st.begin();

            st.erase(st.begin());
            for (auto [to, s]: g[v]) {
                int mx1 = mx, cnt = (s - dis[v][mx].second);

                if (w[to] > w[mx]) {
                    mx1 = to;
                }

                if (cnt > 0) {
                    cnt = (cnt + w[mx] - 1) / w[mx];
                } else {
                    cnt = 0;
                }

                if (dis[to][mx1].first > dis[v][mx].first + cnt) {
                    st.erase({dis[to][mx1].first, -dis[to][mx1].second, to, mx1});

                    dis[to][mx1].first = dis[v][mx].first + cnt;
                    dis[to][mx1].second = dis[v][mx].second + cnt * w[mx] - s;

                    st.insert({dis[to][mx1].first, -dis[to][mx1].second, to, mx1});
                } else if (dis[to][mx1].first == dis[v][mx].first + cnt && dis[to][mx1].second < cnt * w[mx] + dis[v][mx].second - s) {
                    st.erase({dis[to][mx1].first, -dis[to][mx1].second, to, mx1});

                    dis[to][mx1].second = dis[v][mx].second + cnt * w[mx] - s;

                    st.insert({dis[to][mx1].first, -dis[to][mx1].second, to, mx1});
                }
            }
        }

        int res = INF;
        for (int i = 1; i <= n; ++i) {
            res = std::min(res, dis[n][i].first);
        }

        if (res == INF) {
            std::cout << "-1\n";

            exit(0);
        }

        std::cout << res << '\n';
    }

    return 0;
}
