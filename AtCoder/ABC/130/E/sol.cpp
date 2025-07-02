/**
 *    author:  feev1x
 *    created: 17.04.2025 09:12:11
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> s(n), t(m);
    for (auto &u: s) {
        std::cin >> u;
    }

    for (auto &u: t) {
        std::cin >> u;
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int j = 0; j <= m; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            add_self(dp[i][j], dp[i - 1][j]);
            add_self(dp[i][j], dp[i][j - 1]);

            if (s[i - 1] != t[j - 1]) {
                add_self(dp[i][j], -dp[i - 1][j - 1]);
            }
        }
    }

    std::cout << dp[n][m] << '\n';
    return 0;
}
