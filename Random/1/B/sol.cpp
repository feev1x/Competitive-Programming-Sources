/**
 *    author:  feev1x
 *    created: 30.11.2024 12:05:55
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  long double a, b, c; scanf("%Lf%Lf%Lf", &a, &b, &c);
  long double p = (a + b + c) / 2;
  printf("%.10Lf\n", std::sqrt(p * (p - a) * (p - b) * (p - c)));
  return 0;
}
