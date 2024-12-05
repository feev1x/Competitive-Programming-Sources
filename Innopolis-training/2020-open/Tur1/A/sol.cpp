/**
 *    author:  feev1x
 *    created: 22.11.2024 09:03:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  double a, b, x; scanf("%lf%lf%lf", &a, &b, &x);
  if (x == 0) {
    printf("%d\n", 1000 / (int)b * (int)b);
    exit(0);
  }
  if (x == 100) {
    printf("%d\n", 1000 / (int)a * (int)a);
    exit(0);
  }
  int res = 0;
  for (double n = a; n <= 1e5; n += a) {
    double m = (100 * n - x * n) / x;
    if (std::fmod(m, b) == 0) {
      if (n + m <= 1000) {
        res = std::max(res, int(n + m));
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
