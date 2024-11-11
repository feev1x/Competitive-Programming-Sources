/**
 *    author:  feev1x
 *    created: 08.11.2024 17:42:50
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
  int w, h, n; scanf("%d%d%d", &w, &h, &n);
  ll l = 1, r = n, ans = 1e18;
  while (l <= r) {
    ll m = l + r >> 1;
    ll res = m * h;
    res = max(res, ((n + m - 1) / m) * w);
    ans = min(ans, res);
    if (m * h > ((n + m - 1) / m) * w) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
