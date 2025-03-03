/**
 *    author:  feev1x
 *    created: 27.02.2025 13:53:24
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b; std::cin >> a >> b;    

    std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1, a * b));
    std::queue<std::pair<int, int>> q;

    for (int i = 1; i <= std::min(a, b); ++i) {
        dp[i][i] = 0;

        q.emplace(i, i);
    }


    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 1; k + i <= a; ++k) {
            if (dp[i + k][j] > dp[i][j] + 1 + dp[k][j]) {
                dp[i + k][j] = dp[i][j] + 1 + dp[k][j];

                q.emplace(i + k, j);
            }
        }

        for (int k = 1; k + j <= b; ++k) {
            if (dp[i][j + k] > dp[i][j] + 1 + dp[i][k]) {
                dp[i][j + k] = dp[i][j] + 1 + dp[i][k];

                q.emplace(i, j + k);
            }
        }
    }

    std::cout << dp[a][b] << '\n';
    return 0;
}
