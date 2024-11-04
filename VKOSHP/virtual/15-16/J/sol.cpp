/**
 *    author:  feev1x
 *    created: 15.10.2024 09:56:20
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
  int mn = c - d;
  int mx = c - e;
  int res1 = (mx - a) + min(d - 1, min(b, c) - mn);
  int res2 = (b - a + 1) + (d == e ? -1 : -2);
  cout << res1 << ' ' << res2 << '\n';
}
