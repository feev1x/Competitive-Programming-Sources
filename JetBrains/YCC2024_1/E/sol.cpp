/**
 *    author:  feev1x
 *    created: 30.10.2024 08:21:37
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
    int k, x, a; scanf("%d%d%d", &k, &x, &a);
    bool flag = false;
    int nw = a;
    for (int i = 1; i <= x + 1; ++i) {
      int num = (a - nw) / (k - 1) + 1;
      assert(k * num + nw - num > a);
      if (num <= nw) {
        nw -= num;
        flag = true;
      } else {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
