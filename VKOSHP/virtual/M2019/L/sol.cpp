/**
 *    author:  feev1x
 *    created: 12.11.2024 09:20:47
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

double slope(double x, double y) {
  return y / x;
}

int main() {
  double a, b, d, l; scanf("%lf%lf%lf%lf", &a, &b, &d, &l);
  if (d > l) {
    double kat = sqrt(d * d - l * l);
    debug(kat, l, d, a, b, slope(0 - a, kat - b), slope(0 - l, kat), kat);
    if (slope(0 - a, kat - b) >= slope(0 - l, kat)) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  } else {
    if (a + d >= l) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}
