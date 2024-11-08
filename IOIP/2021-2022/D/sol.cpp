/**
 *    author:  feev1x
 *    created: 08.11.2024 00:16:30
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
  vector<int> g1(n / 2), g2(n / 2);
  iota(g1.begin(), g1.end(), 1);
  iota(g2.begin(), g2.end(), n / 2 + 1);
  printf("%d\n", n / 2);
  for (int i = 0; i < n / 2; ++i) {
    for (int j = i + 1; j < n / 2; ++j) {
      printf("%d %d\n", g1[i], g1[j]);
      printf("%d %d\n", g2[i], g2[j]);
    }
    for (int j = i; j >= 0; --j) {
      printf("%d %d\n", g1[i], g2[j]);
      if (i != j) {
        printf("%d %d\n", g2[i], g1[j]);
      }
    }
    if (n & 1) {
      printf("%d %d\n", g1[i], n);
    }
    printf("\n");
  }
  return 0;
}
