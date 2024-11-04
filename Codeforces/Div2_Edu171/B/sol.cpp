/**
 *    author:  feev1x
 *    created: 28.10.2024 20:51:24
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
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (n & 1) {
      int64_t res = 1e18;
      for (int l = 0; l < n; ++l) {
        int64_t ans = 1;
        for (int i = 1; i < n; i += 2) {
          int64_t dif = a[i] - a[i - 1];
          if (i == l || i - 1 == l) {
            if (i - 1 == l) i++, dif = a[i] - a[i - 1];
            else { 
              ans = 1e18;
              break;
            }
          }
          ans = max(ans, dif);
        }
        res = min(res, ans);
      }
      cout << res << '\n';
    } else {
      int64_t res = 0;
      for (int i = 1; i < n; i += 2) {
        res = max(res, a[i] - a[i - 1]);
      }
      cout << res << '\n';
    }
  }
  return 0;
}
