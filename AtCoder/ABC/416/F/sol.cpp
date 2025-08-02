/**
 *    author:  feev1x
 *    created: 26.07.2025 19:08:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int64_t> a(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) 
        std::cin >> a[i];

    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector dp(n + 1, std::vector<std::array<int64_t, 2>>(k + 1, {0, 0}));
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        for (auto to: g[v]) {
            if (to == p)
                continue;

            self(self, to, v);
        }

        for (int i = 0; i <= k; ++i) {
            std::vector<std::array<int64_t, 3>> d(i + 1, {0, 0, 0});

            for (auto to: g[v]) {
                if (to == p)
                    continue;

                auto new_d = d;

                for (int j = 0; j <= i; ++j)
                    for (int l = 0; l <= j; ++l)
                        for (int chs = 0; chs <= 2; ++chs)
                            new_d[j][chs] = std::max(new_d[j][chs], d[l][chs] + dp[to][j - l][0]);

                for (int j = 0; j <= i; ++j)
                    for (int l = 0; l <= j; ++l)
                        for (int chs = 0; chs < 2; ++chs)
                            new_d[j][chs + 1] = std::max(new_d[j][chs + 1], d[l][chs] + dp[to][j - l][1]);

                d = new_d;
            }

            if (i > 0)
                dp[v][i][0] = std::max({dp[v][i][0], d[i - 1][2] + a[v], d[i - 1][1] + a[v], d[i][0], d[i - 1][0] + a[v]});

            dp[v][i][1] = std::max({dp[v][i][1], d[i][0] + a[v], d[i][1] + a[v]});
        }
    };

    Dfs(Dfs, 1, 1);

    int64_t res = 0;
    for (int i = 0; i <= k; ++i)
        res = std::max(res, dp[1][i][0]);

    std::cout << res << '\n';
    return 0;
}
