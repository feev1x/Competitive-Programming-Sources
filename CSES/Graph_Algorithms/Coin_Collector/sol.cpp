/**
 *    author:  feev1x
 *    created: 04.03.2025 04:27:38
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n + 1), comp(n + 1), ord;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> g(n + 1), r_g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        r_g[v].emplace_back(u);
    }

    {
        std::vector<bool> used(n + 1);

        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: g[v]) {
                if (used[to]) {
                    continue;
                }

                self(self, to);
            }

            ord.emplace_back(v);
        };

        for (int i = 1; i <= n; ++i) {
            if (used[i]) {
                continue;
            }

            Dfs(Dfs, i);
        }

        std::reverse(ord.begin(), ord.end());
    }

    int cnt = 0;
    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;
        comp[v] = cnt;

        for (auto to: r_g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }
    };

    for (auto v: ord) {
        if (used[v]) {
            continue;
        }

        cnt++;
        Dfs(Dfs, v);
    }

    std::vector<int64_t> coins(cnt + 1), dp(cnt + 1);
    std::vector<std::vector<int>> adj(cnt + 1);
    std::set<std::pair<int, int>> st;
    for (int v = 1; v <= n; ++v) {
        coins[comp[v]] += a[v];

        for (auto to: g[v]) {
            if (comp[v] == comp[to]) {
                continue;
            }

            st.emplace(comp[v], comp[to]);
        }
    }

    for (auto [u, v]: st) {
        adj[u].emplace_back(v);
    }

    for (int i = 1; i <= cnt; ++i) {
        dp[i] = std::max(dp[i], coins[i]);

        for (auto to: adj[i]) {
            dp[to] = std::max(dp[to], dp[i] + coins[to]);
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
