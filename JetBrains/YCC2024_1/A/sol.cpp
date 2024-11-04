/**
 *    author:  feev1x
 *    created: 30.10.2024 07:52:10
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
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    if (c & 1) {
      if (a >= b) printf("First\n");
      else printf("Second\n");
    } else {
      if (a > b) printf("First\n");
      else printf("Second\n");
    }
  }
  return 0;
}
