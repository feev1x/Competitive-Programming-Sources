#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline void solve() {
    int n, vl = 0, _t = 0; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<int> ans(n + 1), mx(n + 1), dp(n + 1), p(n + 1), tin(n + 1), tout(n + 1);
    for (int i = 1; i < n; ++i) if (g[i].size() == 1) vl = std::max(vl, i);
    if (g[n].size() == 1) return std::cout << "1\n", void();
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        for (auto to: g[v]) if (to != p) {
            self(self, to, v);
            mx[v] = std::max({mx[v], mx[to], to});
        }
        tout[v] = ++_t;
    }; Dfs(Dfs, n, n);
    dp[vl] = p[vl] = 1;
    for (int i = vl + 1; i < n; ++i) {
        p[i] = p[i - 1];
        if (mx[i] + 1 >= i) continue;
        dp[i] = p[i - 1];
        add_self(dp[i], -p[mx[i]]);
        add_self(p[i], dp[i]);
    }
    int in = tin[n - 1], out = tout[n - 1];
    for (int i = 1; i < n; ++i) if (tin[i] <= in && out <= tout[i]) in = tin[i], out = tout[i];
    for (int i = n - 1; i > 0; --i) {
        if (in <= tin[i] && tout[i] <= out) add_self(dp[n], dp[i]);
        else break;
    }
    std::cout << dp[n] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
