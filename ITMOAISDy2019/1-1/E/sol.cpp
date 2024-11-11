/**
 *    author:  feev1x
 *    created: 08.11.2024 17:28:07
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
  int n; scanf("%d", &n);
  vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  sort(a.begin(), a.end());
  int k; scanf("%d", &k);
  while (k--) {
    int l, r; scanf("%d%d", &l, &r);
    printf("%d ", int(upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l)));
  }
  return 0;
}
