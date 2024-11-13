/**
 *    author:  feev1x
 *    created: 13.11.2024 08:13:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  int ls = 0, num = 1 << k;
  i64 res = 0;
  for (int i = 0; i < k; ++i) {
    int u; scanf("%d", &u);
    res += (i64)num * (u - ls);
    ls = u;
    num >>= 1;
  }
  res += n - ls;
  printf("%lld\n", res);
  return 0;
}
