/**
 *    author:  feev1x
 *    created: 16.11.2024 12:57:12
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 109;

int main() {
  int v, t; scanf("%d%d", &v, &t);
  printf("%d\n", ((v * t % mod) + mod) % mod);
  return 0;
}
