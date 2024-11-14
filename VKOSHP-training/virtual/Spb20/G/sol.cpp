/**
 *    author:  feev1x
 *    created: 08.11.2024 15:36:37
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
  int n; ld v, u; scanf("%d%Lf%Lf", &n, &v, &u);
  vector<ld> a(n);
  for (auto &x: a) {
    scanf("%Lf", &x);
  }
  ld l = 0, r = 1e9, ans = 0;
  for (int i = 0; i < 100; ++i) {
    ld m = (l + r) / 2;
    ld we = 0;
    for (auto x: a) {
      we += max(ld(0), (x - m * v) / u);
    }
    if (we > m) {
      l = m + 1e-7;
    } else {
      r = m - 1e-7;
      ans = m;
    }
    debug(l, r);
  }
  printf("%.7Lf\n", ans * u);
  return 0;
}
