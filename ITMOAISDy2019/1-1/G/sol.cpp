/**
 *    author:  feev1x
 *    created: 08.11.2024 17:35:37
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
  int n, x, y; scanf("%d%d%d", &n, &x, &y);
  if (x > y) swap(x, y);
  int l = 0, r = 2e9 + 7, ans = -1;
  while (l <= r) {
    int m = l + r >> 1;
    int cnt = m / x;
    if (m >= x) {
      cnt += (m - x) / y;
    }
    if (cnt >= n) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
