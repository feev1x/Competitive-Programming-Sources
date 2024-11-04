/**
 *    author:  feev1x
 *    created: 28.10.2024 10:35:03
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t a, b; cin >> a >> b;
  int64_t x, y; cin >> x >> y;
  int64_t l = 1, r = a + b, ans = 0, dif = 1e18, sum = x * a + y * b;
  while (l <= r) {
    int64_t m = l + r >> 1;
    int64_t tom = 0, gek = 0;
    if (m >= a) {
      tom = x * a + (m - a) * y;
    } else {
      tom = x * m;
    }
    gek = sum - tom;
    if (dif > abs(tom - gek)) {
      dif = abs(tom - gek);
      ans = m;
    }
    if (tom > gek) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}

