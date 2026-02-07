#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void chmin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::vector<bool>> adj(n, std::vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v, --u, --v;

        adj[u][v] = adj[v][u] = true;
    }

    std::vector<int> dp(1 << n, INF), cost(1 << n);

    for (int mask = 0; mask < 1 << n; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                for (int j = i + 1; j < n; ++j) {
                    if ((mask >> j & 1) && adj[i][j]) {
                        cost[mask]++;
                    } else if (mask >> j & 1) {
                        cost[mask]--;
                    }
                }
            }
        }
    }
    
    dp[0] = n * (n - 1) / 2 - m;
    for (int mask = 1; mask < 1 << n; ++mask) {
        for (int smask = mask; smask; smask = (smask - 1) & mask) {
            chmin(dp[mask], dp[smask ^ mask] + cost[smask]);
        }
    }

    std::cout << dp.back() << '\n';
    return 0;
}
