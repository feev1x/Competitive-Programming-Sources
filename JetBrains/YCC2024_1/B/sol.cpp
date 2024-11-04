/**
 *    author:  feev1x
 *    created: 30.10.2024 07:58:13
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
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    if (n > 19) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    int num = 1;
    for (int i = 0; i < n; ++i) {
      printf("%d ", num);
      num *= 3;
    }
    printf("\n");
  }
  return 0;
}
