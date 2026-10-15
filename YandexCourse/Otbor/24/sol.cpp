#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::string> s(n);
  for (auto &u: s) std::cin >> u;
  std::vector dp(n, std::vector<int>(3, -1));
  for (int i = 0; i < 3; ++i) {
    if (s[0][i] == 'C') dp[0][i] = 1;
    if (s[0][i] == '.') dp[0][i] = 0;
  }
  int res = 0;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < 3; ++j) if (dp[i][j] != -1) {
      if (j > 0 && s[i + 1][j - 1] != 'W' && dp[i + 1][j - 1] < dp[i][j] + (s[i + 1][j - 1] == 'C'))
        dp[i + 1][j - 1] = dp[i][j] + (s[i + 1][j - 1] == 'C');
      if (j < 2 && s[i + 1][j + 1] != 'W' && dp[i + 1][j + 1] < dp[i][j] + (s[i + 1][j + 1] == 'C'))
        dp[i + 1][j + 1] = dp[i][j] + (s[i + 1][j + 1] == 'C');
      if (s[i + 1][j] != 'W' && dp[i + 1][j] < dp[i][j] + (s[i + 1][j] == 'C'))
        dp[i + 1][j] = dp[i][j] + (s[i + 1][j] == 'C');
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) res = std::max(res, dp[i][j]);
  std::cout << res << '\n';
  return 0;
}
