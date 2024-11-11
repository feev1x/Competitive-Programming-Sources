/**
 *    author:  feev1x
 *    created: 10.11.2024 23:11:33
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
    int n, m; scanf("%d%d", &n, &m);
    bool zer = false, brk = false;;
    int sum = 0, um = 1;
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      if (brk) continue;
      sum += u;
      if (u == 0) {
        zer = true;
      }
      if (u > 1) {
        um *= u;
        if (um > m) {
          brk = true;
        }
      }
    }
    if (sum == m || zer && m == 0 || um == m || sum + um == m) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
