/**
 *    author:  feev1x
 *    created: 02.02.2025 21:19:35
**/
#include <bits/stdc++.h>

inline void umin(int64_t &a, int64_t b) {
    if (b == -1) {
        return;
    }

    if (a == -1 || a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, s1, s2; std::cin >> n >> s1 >> s2;

        int m1; std::cin >> m1;

        std::vector<std::vector<int64_t>> g1(n + 1), g2(n + 1);
        for (int i = 0; i < m1; ++i) {
            int u, v; std::cin >> u >> v;
            
            g1[u].emplace_back(v);
            g1[v].emplace_back(u);
        }

        int m2; std::cin >> m2;
        for (int i = 0; i < m2; ++i) {
            int u, v; std::cin >> u >> v;

            g2[u].emplace_back(v);
            g2[v].emplace_back(u);
        }

        std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(n + 1, -1));

        std::set<std::tuple<int64_t, int, int>> st;

        st.emplace(0ll, s1, s2);
        dp[s1][s2] = 0;

        while (st.size()) {
            auto [_, v1, v2] = *st.begin();
            st.erase(st.begin());

            for (auto u1: g1[v1]) {
                for (auto u2: g2[v2]) {
                    if (dp[u1][u2] == -1 || dp[u1][u2] > dp[v1][v2] + std::abs(u1 - u2)) {
                        st.erase({dp[u1][u2], u1, u2});
                        dp[u1][u2] = dp[v1][v2] + std::abs(u1 - u2);
                        st.emplace(dp[u1][u2], u1, u2);
                    }
                }
            }
        }

        int64_t res = -1;
        for (int i = 1; i <= n; ++i) {
            std::vector<bool> vis(n + 1);
            for (auto to: g1[i]) {
                vis[to] = true;
            }

            for (auto to: g2[i]) {
                if (vis[to]) {
                    umin(res, dp[i][i]);

                    break;
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
