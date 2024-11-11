/**
 *    author:  feev1x
 *    created: 08.11.2024 17:56:38
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
  ld c; scanf("%Lf", &c);
  ld l = 0, r = c, ans = 0;
  int t = 100;
  while (t--) {
    ld m = (l + r) / 2;
    if (m * m + sqrt(m) >= c) {
      r = m - 1e-7;
      ans = m;
    } else {
      l = m + 1e-7;
    }
  }
  printf("%.7Lf", ans);
  return 0;
}
