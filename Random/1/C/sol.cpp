/**
 *    author:  feev1x
 *    created: 30.11.2024 12:07:35
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  printf("%d\n%d\n%d\n", std::min({a, b, c}), a + b + c - std::min({a, b, c}) - std::max({a, b, c}), std::max({a, b, c}));
  return 0;
}
