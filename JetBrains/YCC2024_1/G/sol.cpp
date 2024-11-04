/**
 *    author:  feev1x
 *    created: 30.10.2024 10:11:40
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

ll cells_turned_on(int n, int x, int y, int m) {
  ll total = 1;
  total += min(m, x - 1);
  total += min(m, n - x);
  total += min(m, y - 1);
  total += min(m, n - y);
  if (m > 1) {
    int up_left = min({m - 1, x - 1, y - 1});
    int up_right = min({m - 1, x - 1, n - y});
    int down_left = min({m - 1, n - x, y - 1});
    int down_right = min({m - 1, n - x, n - y});
    total += up_left + up_right + down_left + down_right;
  }
  return total;
}

signed main() {
  int n, x, y, c; scanf("%d%d%d%d", &n, &x, &y, &c);
  int l = 0, r = 2 * n, ans = 0;
  while (l <= r) {
    int m = l + r >> 1;
    int on = cells_turned_on(n, x, y, m);
    on *= on;
    if (on == c) {
      ans = m;
      break;
    }
    if (on > c) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
