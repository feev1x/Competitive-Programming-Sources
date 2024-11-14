/**
 *    author:  feev1x
 *    created: 17.10.2024 15:10:17
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
//  freopen("python.in", "r", stdin);
//  freopen("python.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  if (n < m) {
    cout << "0\n0\n";
  } else {
    cout << n / (m + 1) << '\n';
    cout << n / m << '\n';
  }
  return 0;
}
