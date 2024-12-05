/**
 *    author:  feev1x
 *    created: 24.11.2024 15:05:35
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 a, b; scanf("%lld%lld", &a, &b);
  i64 k; scanf("%lld", &k);
  if (k >= b) {
    printf("0\n");
    exit(0);
  }
  i64 res = 1e18;
  for (i64 x = 1; x <= k; ++x) {
    i64 num = b - a * x % b;
    if (num == a * x % b) {
      num *= (a * x % 2) * a;
    } else {
      num *= a * x;
    }
    if (res > num) {
      res = num;
    }
  }
  printf("%lld\n", res);
  return 0;
}
