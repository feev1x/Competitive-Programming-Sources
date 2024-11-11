/**
 *    author:  feev1x
 *    created: 10.11.2024 22:08:52
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; ll v; scanf("%d%d%lld", &n, &m, &v);
    std::vector<ll> a(n + 1), dp(n + 1), dp1(n + 1), pref(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      pref[i] = pref[i - 1] + a[i];
      dp[i] = dp[i - 1];
      sum += a[i];
      if (sum >= v) {
        dp[i]++;
        sum = 0;
      }
    }
    sum = 0;
    for (int i = n; i >= 1; --i) {
      dp1[n - i + 1] = dp1[n - i];
      sum += a[i];
      if (sum >= v) {
        dp1[n - i + 1]++;
        sum = 0;
      }
    }
    if (dp[n] < m && dp1[n] < m) {
      printf("-1\n");
      continue;
    }
    ll res = 0;
    for (int i = 0; i <= n; ++i) {
      int j = std::lower_bound(dp1.begin(), dp1.end(), m - dp[i]) - dp1.begin();
      j = n - j + 1;
      j--;
      res = std::max(res, pref[j] - pref[i]);
    }
    printf("%lld\n", res);
  }
  return 0;
}
