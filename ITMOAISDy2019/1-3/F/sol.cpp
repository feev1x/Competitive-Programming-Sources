/**
 *    author:  feev1x
 *    created: 10.11.2024 18:50:18
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
  int n; scanf("%d", &n);
  std::vector dp(n + 1, std::vector<int>(n + 1, 1e9));
  std::vector p(n + 1, std::vector<int>(n + 1, -1));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int u; scanf("%d", &u);
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] > dp[i - 1][j + 1]) {
        dp[i][j] = dp[i - 1][j + 1];
        p[i][j] = j + 1;
      }
    }
    if (u > 100) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i][j] > dp[i - 1][j - 1] + u) {
          dp[i][j] = dp[i - 1][j - 1] + u;
          p[i][j] = j - 1;
        }
      }
    } else {
      for (int j = 0; j <= n; ++j) {
        if (dp[i][j] > dp[i - 1][j] + u) {
          dp[i][j] = dp[i - 1][j] + u;
          p[i][j] = j;
        }
      }
    }
  }
  int res = 1e9 + 2, k1 = -1;
  for (int i = n; i >= 0; --i) {
    if (res > dp[n][i]) {
      res = dp[n][i];
      k1 = i;
    }
  }
  assert(k1 != -1);
  std::vector<int> ans;
  int j = p[n][k1], nw = k1;
  for (int i = n; i >= 1; --i) {
    if (nw + 1 == j) {
      ans.emplace_back(i);
    }
    nw = j;
    j = p[i - 1][nw];
  }
  std::reverse(ans.begin(), ans.end());
  debug(dp, p);
  printf("%d\n%d %d\n", dp[n][k1], k1, int(ans.size()));
  for (auto u: ans) {
    printf("%d\n", u);
  }
  return 0;
}
