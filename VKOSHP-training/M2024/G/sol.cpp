/**
 *    author:  feev1x
 *    created: 05.11.2024 09:15:10
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
    vector<tuple<int, int, int, int>> a;
    for (int i = 0; i < n; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      a.emplace_back(max(u, v), min(u, v), u, v);
    }
    sort(a.begin(), a.end());
    for (auto [mx, mn, u, v]: a) {
      printf("%d %d ", u, v);
    }
    printf("\n");
  }
  return 0;
}
