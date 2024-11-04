/**
 *    author:  feev1x
 *    created: 19.10.2024 18:07:06
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
  int n, c; cin >> n >> c;
  int ls = -10000, cnt = 0;
  for (int i = 0; i < n; ++i) {
    int u; cin >> u;
    if (u - ls >= c) {
      cnt++;
      ls = u;
    }
  }
  cout << cnt << '\n';
  return 0;
}
