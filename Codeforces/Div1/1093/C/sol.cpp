#include <bits/stdc++.h>

#define double long double

constexpr double INF = 1e10;

inline void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    s = " " + s;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(2, INF));
    for (int i = 1; i <= n; ++i) if (s[i] == '1') dp[i][0] = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        double sum = 0, cn = g[v].size(), cn2 = g[v].size() - 1;
        if (v == 1) cn2++;
        for (auto to: g[v]) if (to != p) {
            self(self, to, v);
            if (s[v] == '1') dp[v][0] += std::min(dp[to][0], dp[to][1]);
            else sum += dp[to][0];
        }
        if (s[v] == '0') {
            std::sort(g[v].begin(), g[v].end(), [&](int i, int j) {
                return dp[i][1] - dp[i][0] < dp[j][1] - dp[j][0];
            });
            if (cn2) dp[v][0] = cn / cn2 + sum;
            dp[v][1] = cn / (cn2 + 1) + sum;
            for (auto to: g[v]) if (to != p) {
                cn2--;
                sum += dp[to][1] - dp[to][0];
                if (cn2) dp[v][0] = std::min(dp[v][0], cn / cn2 + sum);
                dp[v][1] = std::min(dp[v][1], cn / (cn2 + 1) + sum);
            }
        }
    }; Dfs(Dfs, 1, 1);
    std::cout << std::fixed << std::setprecision(10) << dp[1][0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
