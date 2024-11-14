/**
 *    author:  feev1x
 *    created: 22.10.2024 18:57:15
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
  double n, T; cin >> n >> T;  
  double m; cin >> m;
  double x, y; cin >> x >> y;
  T *= 60;
  n -= m;
  double time = m / x;
  time += n / y;
  cout << (T > time ? 0 : ceil((time - T) / 60)) << '\n';
  return 0;
}
