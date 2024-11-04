/**
 *    author:  feev1x
 *    created: 29.10.2024 14:00:37
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
  int n, b, p; cin >> n >> b >> p;
  int bot = 0, pol = n * p;
  while (n > 1) {
    int k = (1 << int(log2(n)));
    n -= k / 2;
    debug(k);
    bot += b * k + k / 2;
  }
  cout << bot << ' ' << pol << '\n';
  return 0;
}
