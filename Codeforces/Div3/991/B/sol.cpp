/**
 *    author:  feev1x
 *    created: 05.12.2024 20:40:58
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    i64 sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
      i64 u; scanf("%lld", &u);
      if (i & 1) {
        sum1 += u;
      } else {
        sum2 += u;
      }
    }
    if (sum2 % ((n + 1) / 2) == 0 && sum1 % (n / 2) == 0 && sum2 / ((n + 1) / 2) == sum1 / (n / 2)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
