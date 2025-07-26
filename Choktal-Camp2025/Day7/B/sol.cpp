/**
 *    author:  feev1x
 *    created: 07.07.2025 10:00:41
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> mx(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        dp[i][i] = a[i];
        mx[i][i] = a[i];
    }

    for (int i = n - 1; i >= 1; --i) {
        for (int j = i + 1; j <= n; ++j) {
            int l = i, r = j - 1, ans = 1e9;
            while (l <= r) {
                int m = l + r >> 1;

                ans = std::min(ans, std::max(dp[i][m], dp[m + 1][j]) + 1);
                if (dp[i][m] == dp[m + 1][j]) {
                    break;
                }

                if (dp[i][m] > dp[m + 1][j]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            dp[i][j] = ans;
        }
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << dp[l][r] << '\n';
    }

    return 0;
}
