/**
 *    author:  feev1x
 *    created: 01.11.2024 20:45:53
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
    int n, k; scanf("%d%d", &n, &k);
    if (n == 1) {
      printf("1\n1\n");
      continue;
    }
    if (n == k || k == 1) {
      printf("-1\n");
      continue;
    }
    if (k & 1) {
      printf("3\n1 %d %d\n", k - 1, k + 2);
    } else {
      printf("3\n1 %d %d\n", k, k + 1);
    }
  }
  return 0;
}
