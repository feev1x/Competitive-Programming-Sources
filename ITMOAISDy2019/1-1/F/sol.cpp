/**
 *    author:  feev1x
 *    created: 08.11.2024 17:30:51
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
  vector<ll> a(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  while (k--) {
    ll b; scanf("%lld", &b);
    int j = lower_bound(a.begin(), a.end(), b) - a.begin();
    ll dif = 1e18, res = -1;
    if (j != n) {
      res = a[j];
      dif = a[j] - b;
    }
    j--;
    if (j >= 0) {
      if (dif >= b - a[j]) {
        res = a[j];
        dif = b - a[j];
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
