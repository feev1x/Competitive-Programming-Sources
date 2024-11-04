/**
 *    author:  feev1x
 *    created: 30.10.2024 08:08:43
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main() {
  int seg[]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  ll res = 0;
  auto Calc = [&](int a) {
    while (a > 0) {
      res += seg[a % 10];
      a /= 10;
    }
  };
  int a, b; scanf("%d%d", &a, &b);
  for (int v = a; v <= b; ++v) {
    Calc(v);
  }
  printf("%lld\n", res);
  return 0;
}
