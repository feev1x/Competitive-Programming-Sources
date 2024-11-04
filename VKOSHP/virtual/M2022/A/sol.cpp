/**
 *    author:  feev1x
 *    created: 18.10.2024 09:04:11
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
  int n; cin >> n;
  int x, y; cin >> x >> y;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  int res = int(log2(n));

  return 0;
}
