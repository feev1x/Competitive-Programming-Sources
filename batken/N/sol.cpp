/**
 *    author:  feev1x
 *    created: 16.11.2024 12:49:15
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  double h, a, b; scanf("%lf%lf%lf", &h, &a, &b);
  double day = (h - a) / (a - b);
  printf("%d\n", (int)std::ceil(day + 1));
  return 0;
}
