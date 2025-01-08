/**
 *    author:  feev1x
 *    created: 09.11.2024 20:35:45
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
    ll l, r, k; scanf("%lld%lld%lld", &l, &r, &k);
    ll nx = l * k;
    if (nx > r) {
      printf("0\n");
      continue;
    }
    printf("%lld\n", (r - nx + k) / k);
  }
  return 0;
}
