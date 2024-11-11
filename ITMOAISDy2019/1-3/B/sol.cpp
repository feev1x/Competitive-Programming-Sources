/**
 *    author:  feev1x
 *    created: 10.11.2024 17:13:51
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector a(n + 1, std::vector<int>(m + 1));
  std::vector dp(n + 1, std::vector<int>(m + 1, -1e9));
  std::vector p(n + 1, std::vector<char>(m + 1, '-'));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      if (i == 1 && j == 1) {
        dp[i][j] = a[i][j];
        continue;
      }
      if (dp[i - 1][j] > dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j] + a[i][j];
        p[i][j] = 'D';
      } else if (dp[i - 1][j] < dp[i][j - 1]) {
        dp[i][j] = dp[i][j - 1] + a[i][j];
        p[i][j] = 'R';
      } else {
        if (i == 1) {
          dp[i][j] = dp[i][j - 1] + a[i][j];
          p[i][j] = 'R';
        } else {
          dp[i][j] = dp[i - 1][j] + a[i][j];
          p[i][j] = 'D';
        }
      }
    }
  }
  printf("%d\n", dp[n][m]); 
  std::string res;
  int i = n, j = m;
  while (p[i][j] != '-') {
    res += p[i][j];
    if (p[i][j] == 'D') {
      i--;
    } else {
      j--;
    }
  }
  std::reverse(res.begin(), res.end());
  printf("%s\n", res.c_str());
  return 0;
}
