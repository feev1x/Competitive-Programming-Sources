/**
 *    author:  feev1x
 *    created: 29.10.2024 14:06:48
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
  int n, a; cin >> n >> a;
  int res = 0;
  for (int l = 1, r = n; l <= n && r >= 1; l += 2, r -= 2) {
    res++;
    if (l == a || r == a) {
      break;
    }
  }
  cout << res << '\n';
  return 0;
}
