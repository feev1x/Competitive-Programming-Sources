/**
 *    author:  feev1x
 *    created: 17.10.2024 15:20:27
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
//  freopen("loudcats.in", "r", stdin);
//  freopen("loudcats.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a; cin >> n >> m >> a;
  vector<int> b(n * m);
  for (auto &u: b) cin >> u;
  int res = 0;
  for (int i = 0; i + m < n * m; ++i) {
    if (b[i + m] > b[i] * 2) {
      res += a;
    }
  }
  cout << res << '\n';
  return 0;
}
