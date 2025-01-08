/**
 *    author:  feev1x
 *    created: 02.11.2024 18:03:40
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
  int n; scanf("%d", &n);
  vector<int> q(n), r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &q[i], &r[i]);
  }
  int Q; scanf("%d", &Q);
  while (Q--) {
    int t, d; scanf("%d%d", &t, &d); t--;
    if (d % q[t] <= r[t]) {
      printf("%d\n", d / q[t] * q[t] + r[t]);
      continue;
    }
    printf("%d\n", d / q[t] * q[t] + r[t] + q[t]);
  }
  return 0;
}
