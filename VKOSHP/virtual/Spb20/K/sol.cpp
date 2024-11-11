/**
 *    author:  feev1x
 *    created: 08.11.2024 09:24:30
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
  ll a, b; scanf("%lld%lld", &a, &b);
  if (a >= b) {
    printf("%lld\n", b);
  } else {
    printf("%lld\n", a + 1);
  }
  return 0;
}
