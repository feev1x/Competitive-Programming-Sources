/**
 *    author:  feev1x
 *    created: 27.10.2024 20:49:53
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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    if (n == 1 || n == 3) {
      cout << "-1\n";
      continue;
    }
    if (n & 1) {
      string ans;
      for (int i = 0; i < n - 5; ++i) ans += "3";
      cout << ans + "36366" << '\n';
    } else {
      string ans;
      for (int i = 0; i < n - 2; ++i) ans += "3";
      cout << ans + "66" << '\n';
    }
  }
  return 0;
}
