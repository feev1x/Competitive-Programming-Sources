/**
 *    author:  feev1x
 *    created: 08.11.2024 17:19:44
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
  int u;
  vector<int> a;
  while (scanf("%d", &u)) {
    a.emplace_back(u);
  }
  sort(a.begin(), a.end());
  for (auto u: a) {
    printf("%d ", u);
  }
  return 0;
}
