#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    n = 1 << n;
    std::vector<int> pr(n + 1), sub(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> pr[i];

        g[pr[i]].emplace_back(i);
    }

    std::vector<std::vector<int>> dp(n + 1);
    std::vector<std::vector<std::vector<int>>> p(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        sub[v] = 1;
        
        for (auto to: g[v]) {
            self(self, to);

            sub[v] += sub[to];
        }

        if (g[v].size() == 1) {
            int to = g[v][0];
            std::swap(dp[v], dp[to]);
            std::swap(p[v], p[to]);
            dp[v].resize(sub[v] + 1);
            p[v].resize(sub[v] + 1);
        } else if (g[v].size() == 2) {
            int l = g[v][0];
            int r = g[v][1];

            if (sub[l] < sub[r]) {
                std::swap(l, r);
            }

            std::swap(dp[v], dp[l]);
            std::swap(p[v], p[l]);
            l = v;
            dp[v].resize(sub[v] + 1);
            p[v].resize(sub[v] + 1);

            for (int i = sub[l]; i >= (l == v ? 0 : 1); --i) {
                if (dp[l][i] == 0 && i > 0) {
                    continue;
                }

                for (int j = std::min(sub[v] - i, sub[r]); j >= (r == v ? 0 : 1); --j) {
                    if (dp[r][j] == 0 && i > 0) {
                        continue;
                    }

                    if (dp[v][i + j] == 0 || dp[v][i + j] > dp[l][i] + dp[r][j]) {
                        dp[v][i + j] = dp[l][i] + dp[r][j];

                        p[v][i + j] = p[l][i];

                        for (auto u: p[r][j]) {
                            p[v][i + j].emplace_back(u);
                        }
                    }
                }
            }
        }

        dp[v].resize(sub[v] + 1);
        p[v].resize(sub[v] + 1);

        dp[v][0] = 0;
        dp[v][sub[v]] = 1;
        p[v][sub[v]] = std::vector<int>{v};
    };

    Dfs(Dfs, 1);

    std::cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        std::cout << p[1][i].size() << ' ';

        for (auto u: p[1][i]) {
            std::cout << u << ' ';
        }

        std::cout << '\n';
    }
}
