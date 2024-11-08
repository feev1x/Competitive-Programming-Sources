/**
 *    author:  feev1x
 *    created: 08.11.2024 00:25:06
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
  if (a > b) {
    swap(a, b);
  }
  ll cnt = 0;
  while (a && b) {
    cnt += b / a;
    b %= a;
    swap(a, b);
  }
  printf("%lld\n", cnt);
  return 0;
}
