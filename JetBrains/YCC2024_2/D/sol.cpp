/**
 *    author:  feev1x
 *    created: 29.10.2024 09:03:52
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
  int a, b, n; cin >> a >> b >> n;
  int md = (a * 10) % b;
  if (md != 0 && b - md > 9) {
    cout << -1 << '\n';
    return 0;
  }
  cout << a << (md == 0 ? 0 : b - md);
  for (int i = 0; i < n - 1; ++i) cout << 0;
  cout << '\n';
  return 0;
}
