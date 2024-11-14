/**
 *    author:  feev1x
 *    created: 11.11.2024 09:26:39
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  ll a; scanf("%lld", &a);
  ll cnt = __builtin_popcountll(a);
  if (a & 1ll << 31ll) cnt--;
  printf("%lld\n", (1ll << cnt) << 1ll);
  return 0;
}
