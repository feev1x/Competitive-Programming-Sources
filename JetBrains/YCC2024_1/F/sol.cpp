/**
 *    author:  feev1x
 *    created: 30.10.2024 09:06:16
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
    ll n; scanf("%lld", &n);
    ll cnt = 0, a = 3;
    while (a <= n) {
      ll b = (a * a - 1) / 2;
      if (b >= n) break;
      cnt++;
      a += 2;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
