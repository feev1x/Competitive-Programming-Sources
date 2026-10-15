#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 20;

inline void solve() {
    int n, q, _t = 0; std::cin >> n >> q;
    std::vector<int> l(n + 1), r(n + 1), tin(n + 1), dp(n + 1), val(5 * n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i], p[l[i]] = p[r[i]] = i;
    {
        auto Dfs = [&](auto &&self, int v) -> void {
            tin[v] = ++_t, val[tin[v]] = v;
            if (!l[v]) return;
            self(self, l[v]);
            val[++_t] = v;
            self(self, r[v]);
            val[++_t] = v;
            dp[v] = dp[l[v]] + dp[r[v]] + 4;
        }; Dfs(Dfs, 1);
    }
    std::vector<std::vector<int>> anc(n + 1, std::vector<int>(N));
    std::vector<std::vector<int>> cost(n + 1, std::vector<int>(N));
    auto Dfs = [&](auto &&self, int v) -> void {
        anc[v][0] = p[v];
        cost[v][0] = dp[v] + 1;
        for (int i = 1; i < N; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            cost[v][i] = cost[anc[v][i - 1]][i - 1] + cost[v][i - 1];
        }
        if (!l[v]) return;
        self(self, l[v]);
        self(self, r[v]);
    }; Dfs(Dfs, 1);
    auto Get = [&](int v, int k) -> int {
        for (int i = N - 1; i >= 0; --i) if (cost[v][i] <= k) k -= cost[v][i], v = anc[v][i];
        return val[tin[v] + k];
    };
    for (int i = 0; i < q; ++i) {
        int v, k; std::cin >> v >> k;
        std::cout << Get(v, k) << " \n"[i + 1 == q];
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
