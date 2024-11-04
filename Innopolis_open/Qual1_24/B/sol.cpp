/**
 *    author:  feev1x
 *    created: 30.10.2024 14:48:48
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main() {
  int n, x, y; scanf("%d%d%d", &n, &x, &y);
  vector<int> d(n);
  for (auto &u: d) scanf("%d", &u), u = u % (x + y) + 1;
  vector<int> rng;
  for (int i = 0; i < n; ++i) {
    rng.emplace_back(d[i]);
    if (d[i] + y - 1 > x + y) {
      rng.emplace_back(d[i] - x - y);
    }
  }
  sort(rng.begin(), rng.end());
  for (int D = 1; D <= x + y;) {
    auto it = upper_bound(rng.begin(), rng.end(), D - y);
    if (it == rng.end() || D < *it) {
      printf("%d\n", D);
      return 0;
    }
    D = *it + y;
  }
  printf("-1\n");
  return 0;
}
