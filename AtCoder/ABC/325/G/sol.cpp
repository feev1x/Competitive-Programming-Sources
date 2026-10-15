#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int n = s.size(), k; std::cin >> k;
    std::vector dp(n + 1, std::vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = dp[i + 1][s[i] == 'o'];
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i + 1][(s[i] == 'o') * (j + 1)];
            if (s[i] == 'f') {
                for (int ni = i + 1; ni <= std::min(n, i + k + 1); ++ni) {
                    dp[i][j] = std::max(dp[i][j], dp[ni][j - 1] + ni - i + 1);
                }
            }
        }
    }
    std::cout << n - dp[0][0] << '\n';
    return 0;
}
