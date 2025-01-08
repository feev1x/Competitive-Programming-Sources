/**
 *    author:  feev1x
 *    created: 09.11.2024 21:06:13
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<int> a(n + 1), p(n + 1);
    int x = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<array<int, 3>> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i - 1][0] + (dp[i - 1][0] > a[i] ? -1 : dp[i - 1][0] == a[i] ? 0 : 1);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
      int mx = (i > 2 ? dp[i - 1][2] + (dp[i - 1][2] > a[i] ? -1 : dp[i - 1][2] == a[i] ? 0 : 1) : -n);
      if (i > 1) {
        mx = max(mx, dp[i - 1][1] + (dp[i - 1][1] > a[i] ? -1 : dp[i - 1][1] == a[i] ? 0 : 1));
        dp[i][2] = mx;
      }
    }
    printf("%d\n", max(dp[n][1], dp[n][2]));
  }
  return 0;
}
