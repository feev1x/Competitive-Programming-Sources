/**
 *    author:  feev1x
 *    created: 23.10.2024 09:09:40
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
  int tt; cin >> tt;
  while (tt--) {
    int64_t x; cin >> x;
    x = abs(x);
    int64_t cnt = 0;
    while (x > 0) {
      int64_t bit = 63 - __builtin_clzll(x);
      x = min(abs(x - (1ll << (bit + 1))), abs(x - (1ll << bit)));
      cnt++;
    }
    cout << cnt << '\n';
  }
  return 0;
}
