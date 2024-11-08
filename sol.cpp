/**
 *    author:  feev1x
 *    created: 06.11.2024 18:41:43
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
  ll x, d; scanf("%lld%lld", &x, &d);
  ll res = 1e18;
  for (ll i = 0; i <= 1e6; ++i) {
    ll j = 5 * d * d - i * i;
    if (fmod(sqrt(j), 1) == 0) {
      res = min(res, (x - i) * (x - i) + j);
    }
  }
  printf("%lld\n", res);
  return 0;
}
