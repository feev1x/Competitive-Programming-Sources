/**
 *    author:  feev1x
 *    created: 03.03.2025 22:02:28
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    std::queue<int> q;
    std::vector<int> dp(n + 1), ord;
    std::vector<bool> used(n + 1);

    dp[1] = 1;
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

    for (auto v: ord) {
        for (auto to: g[v]) {
            add_self(dp[to], dp[v]);
        }
    }

    std::cout << dp[n] << '\n';
    return 0;
}
