/**
 *    author:  feev1x
 *    created: 03.11.2025 15:21:00
**/
#include <bits/stdc++.h>

#define int int64_t

constexpr int INF = 1e9;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> req(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p; std::cin >> p;

        req[i] = p;

        g[p].emplace_back(i);
    }

    std::vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];

    std::vector<std::array<int, 2>> dp(n + 1, {INF, INF});

    auto Dfs = [&](auto &&self, int v) -> void {
        if (g[v].empty()) {
            dp[v][s[v]] = 0;
            return;
        }

        std::array<int, 2> d{0, INF};
        for (auto to: g[v]) {
            self(self, to);

            auto new_d = d;

            new_d[1] = std::min(d[0] + dp[to][0] + 1, d[1] + dp[to][1]);
            new_d[0] = std::min(d[1] + dp[to][0] + 1, d[0] + dp[to][1]);

            std::swap(new_d, d);
        }

        dp[v][1] = d[s[v] ^ 1];
        dp[v][0] = d[s[v]];
    };

    Dfs(Dfs, 1);

    if (dp[1][1] >= INF)
        std::cout << "-1\n";
    else
        std::cout << dp[1][1] * 2 << '\n';
    return 0;
}
