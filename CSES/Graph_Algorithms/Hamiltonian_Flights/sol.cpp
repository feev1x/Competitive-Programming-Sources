/**
 *    author:  feev1x
 *    created: 04.03.2025 14:41:30
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

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(1 << n));
    std::vector<std::vector<bool>> used(n + 1, std::vector<bool>(1 << n));

    dp[1][1] = 1;

    std::queue<std::pair<int, int>> q;
    used[1][1] = true;

    q.emplace(1, 1);
    while (q.size()) {
        auto [mask, v] = q.front();

        q.pop();
        if (v != n) {
            for (auto to: g[v]) {
                if (mask >> (to - 1) & 1) {
                    continue;
                }

                int new_mask = mask | (1 << to - 1);
                add_self(dp[to][new_mask], dp[v][mask]);
                if (!used[to][new_mask]) {
                    used[to][new_mask] = true;

                    q.emplace(new_mask, to);
                }
            }
        }
    }

    std::cout << dp[n][(1 << n) - 1] << '\n';
    return 0;
}
