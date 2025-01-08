/**
 *    author:  feev1x
 *    created: 16.10.2024 20:43:12
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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> mp(101);
    for (auto &u: a) cin >> u, mp[u]++;
    int64_t res = 0;
    for (int dif = 0; dif < 100; ++dif) {
      for (int i = 0; i + dif < n; ++i) {
        if (abs(a[i] - a[i + dif]) == dif) {
          res += 2 * (dif + 1) / (dif ? 1 : 2);
        } else {
          int dis = abs(a[i] - a[i + dif]);
          dis -= dif;
          if (dis & 1 || dis <= 0) {
            continue;
          }
          int k = i + dif;
          if (i - dis / 2 >= 0) {
            res += 2 / (dif ? 1 : 2);
            debug(i, k, dif, res);
          } 
          if (k + dis / 2 < n) {
            res += 2 / (dif ? 1 : 2);
            debug(i, k, dif, res);
          }
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
