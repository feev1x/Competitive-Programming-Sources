/**
 *    author:  feev1x
 *    created: 27.10.2024 20:35:20
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int n, m, r, c; cin >> n >> m >> r >> c;
    cout << (n - r) * m + (m - c) + m * (n - r) - (n - r) << '\n';
  }
  return 0;
}
