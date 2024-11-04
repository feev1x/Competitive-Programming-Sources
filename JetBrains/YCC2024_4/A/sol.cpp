/**
 *    author:  feev1x
 *    created: 29.10.2024 19:45:14
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
    char c[101]; int n; scanf("%s%n", c, &n); n--;
    if (c[0] == ')' || n & 1 || c[n - 1] == '(') {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
