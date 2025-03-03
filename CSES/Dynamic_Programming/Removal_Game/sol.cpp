/**
 *    author:  feev1x
 *    created: 27.02.2025 14:07:06
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(n + 1, -INF));
    std::vector<std::vector<int64_t>> sum(n + 1, std::vector<int64_t>(n + 1));
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        sum[i][i] = dp[i][i] = a[i];
    }


    for (int l = n; l >= 1; --l) {
        for (int r = l + 1; r <= n; ++r) {
            sum[l][r] = sum[l + 1][r] + a[l];
            dp[l][r] = std::max(sum[l + 1][r] - dp[l + 1][r] + a[l], sum[l][r - 1] - dp[l][r - 1] + a[r]);
        }
    }

    std::cout << dp[1][n] << '\n';
    return 0;
}
