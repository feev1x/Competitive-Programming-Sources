/**
 *    author:  feev1x
 *    created: 27.02.2025 12:26:12
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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 2));

    if (a[1]) {
        dp[1][a[1]] = 1;
    } else {
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i]) {
            add_self(dp[i][a[i]], dp[i - 1][a[i] + 1]);
            add_self(dp[i][a[i]], dp[i - 1][a[i] - 1]);
            add_self(dp[i][a[i]], dp[i - 1][a[i]]);

            continue;
        }

        for (int j = 1; j <= m; ++j) {
            add_self(dp[i][j], dp[i - 1][j + 1]);
            add_self(dp[i][j], dp[i - 1][j - 1]);
            add_self(dp[i][j], dp[i - 1][j]);
        }
    }

    int res = 0;
    for (int i = 1; i <= m; ++i) {
        add_self(res, dp[n][i]);
    }
    
    std::cout << res << '\n';
    return 0;
}
