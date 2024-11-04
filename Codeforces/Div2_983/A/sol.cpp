/**
 *    author:  feev1x
 *    created: 01.11.2024 20:36:18
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
    int n; scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
      int u; scanf("%d", &u);
      sum += u;
      debug(sum, u);
    }
    printf("%d ", sum % 2);
    if (sum > n) {
      printf("%d\n", n - (sum - n));
    } else {
      printf("%d\n", sum);
    }
  }
  return 0;
}
