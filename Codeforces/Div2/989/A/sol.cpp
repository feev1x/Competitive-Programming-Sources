/**
 *    author:  feev1x
 *    created: 30.11.2024 20:36:39
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int a, b; scanf("%d%d", &a, &b);
    int n = std::lcm(a, b);
    printf("%d\n", n);
  }
  return 0;
}
