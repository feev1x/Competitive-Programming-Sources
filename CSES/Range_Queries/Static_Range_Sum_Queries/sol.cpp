/**
 *    author:  feev1x
 *    created: 04.11.2024 22:43:39
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
  int n, q; scanf("%d%d", &n, &q);
  vector<ll> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    p[i] = p[i - 1] + a[i];
  }
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    printf("%lld\n", p[r] - p[l - 1]);
  }
  return 0;
}
