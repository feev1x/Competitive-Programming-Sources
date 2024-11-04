/**
 *    author:  feev1x
 *    created: 01.11.2024 21:02:22
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    sort(a.begin(), a.end());
    int res = n;
    for (int i = 0; i < n - 2; ++i) {
      auto it = lower_bound(a.begin(), a.end(), a[i] + a[i + 1]);
      if (it == a.end()) {
        res = min(res, i);
        break;
      }
      int j = it - a.begin();
      res = min(res, i + n - j);
    }
    printf("%d\n", res);
  }
  return 0;
}
