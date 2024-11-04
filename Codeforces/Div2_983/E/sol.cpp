/**
 *    author:  feev1x
 *    created: 01.11.2024 21:59:14
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
    vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    if (n == 1) {
      printf("0\n");
      continue;
    }
    if (n == 2) {
      if (a[0] == a[1]) {
        printf("0\n0\n");
      } else {
        printf("-1\n");
      }
      continue;
    }
    
  }
  return 0;
}
