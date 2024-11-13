/**
 *    author:  feev1x
 *    created: 13.11.2024 09:15:33
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> a(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  std::vector<std::array<i64, 2>> dp(n + 1);
  std::vector<std::array<int, 2>> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (dp[i - 1][0] > dp[i - 1][1]) {
      dp[i][0] = dp[i - 1][0] + a[i - 1];
      p[i][0] = 0;
    } else {
      dp[i][0] = dp[i - 1][1] + a[i - 1];
      p[i][0] = 1;
    }
    dp[i][1] = dp[i - 1][0] + a[i - 1] * 2;
    p[i][1] = 0;
  }
  int m = (dp[n][1] > dp[n][0] ? 1 : 0);
  printf("%lld\n", dp[n][m]);
  std::string s;
  for (int i = n, j = m; i >= 1; --i) {
    if (j == 1) {
      s += "M";
    } else {
      s += "O";
    }
    j = p[i][j];
  }
  std::reverse(s.begin(), s.end());
  printf("%s\n", s.c_str());
  return 0;
}
