/**
 *    author:  feev1x
 *    created: 08.11.2024 22:00:42
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
  int n, k; scanf("%d%d", &n, &k);
  vector<pair<ld, ld>> a(n);
  for (int i = 0; i < n; ++i) {
    int v, w; scanf("%d%d", &v, &w);
    a[i] = {v, w};
  }
  ld l = 0, r = 1e7, ans = 0;
  for (int i = 0; i < 100; ++i) {
    ld m = (l + r) / 2;
    vector<ld> sm;
    for (auto [v, w]: a) {
      sm.emplace_back(v - m * w);
    }
    sort(sm.begin(), sm.end(), greater<>());
    if (accumulate(sm.begin(), sm.begin() + k, ld(0)) >= 0) {
      l = m + 1;
      ans = m;
    } else {
      r = m - 1;
    }
  }
  vector<pair<ld, int>> sm;
  for (int i = 0; i < n; ++i) {
    auto [v, w] = a[i];
    sm.emplace_back(v - ans * w, i + 1);
  }
  sort(sm.begin(), sm.end(), greater<>());
  for (int i = 0; i < k; ++i) {
    printf("%d\n", sm[i].second);
  }
  return 0;
}
