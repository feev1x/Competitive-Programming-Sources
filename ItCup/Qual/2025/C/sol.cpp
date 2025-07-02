/**
 *    author:  feev1x
 *    created: 06.04.2025 11:32:26
**/
#include <bits/stdc++.h>

inline void max_self(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int v1, v2, n; std::cin >> v1 >> v2 >> n;

    std::vector<int> cost(n + 1), vol(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> vol[i] >> cost[i];
    }

    std::vector<std::vector<int>> dp(v1 + 1, std::vector<int>(v2 + 1));

    for (int i = 1; i <= n; ++i) {
        auto new_dp = dp;

        for (int x = 0; x <= v1; ++x) {
            for (int y = vol[i]; y <= v2; ++y) {
                max_self(new_dp[x][y], dp[x][y - vol[i]] + cost[i]);
            }
        }

        for (int x = vol[i]; x <= v1; ++x) {
            for (int y = 0; y <= v2; ++y) {
                max_self(new_dp[x][y], dp[x - vol[i]][y] + cost[i]);
            }
        }

        dp = new_dp;
    }

    int res = 0;
    for (int i = 0; i <= v1; ++i) {
        for (int j = 0; j <= v2; ++j) {
            max_self(res, dp[i][j]);
        }
    }

    std::cout << res << '\n';
    return 0;
}
