/**
 *    author:  feev1x
 *    created: 10.11.2024 17:00:52
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
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> a(n + 1), dp(n + 1, -1e9), p(n + 1, -1);
  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (i != n) {
      scanf("%d", &a[i]);
    }
    for (int j = 1; j <= std::min(i - 1, k); ++j) {
      if (dp[i] < dp[i - j] + a[i]) {
        dp[i] = dp[i - j] + a[i];
        p[i] = i - j;
      }
    }
  }
  printf("%d\n", dp[n]);
  std::vector<int> ans;
  for (int v = n; v != -1; v = p[v]) {
    ans.emplace_back(v);
  }
  std::reverse(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size() - 1);
  for (auto u: ans) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
