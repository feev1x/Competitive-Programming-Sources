/**
 *    author:  feev1x
 *    created: 10.11.2024 21:43:51
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
  int tt; scanf("%d", &tt);
  while (tt--) {
    ll n, b, c; scanf("%lld%lld%lld", &n, &b, &c);
    if (b == 0) {
      if (c < n - 2) {
        printf("-1\n");
      } else {
        printf("%lld\n", c >= n ? n : n - 1);
      }
      continue;
    }
    ll cnt = (n - c - 1) / b + 1;
    if (c >= n) cnt = 0;
    printf("%lld\n", n - cnt);
  }
  return 0;
}
