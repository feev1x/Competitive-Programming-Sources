/**
 *    author:  feev1x
 *    created: 16.10.2024 20:15:01
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
      int u; cin >> u;
      if (u & 1) {
        odd++;
      } else {
        even++;
      }
    }
    if (odd == 0) {
      cout << 0 << '\n';
      continue;
    }
    int cnt = even + 1;
    odd--;
    cnt += odd / 2;
    cout << cnt << '\n';
  }
  return 0;
}
