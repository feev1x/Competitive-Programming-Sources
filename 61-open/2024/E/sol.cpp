/**
 *    author:  feev1x
 *    created: 24.11.2024 10:59:14
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<i64>> a(n, std::vector<i64>(m));
  for (auto &u: a) {
    for (auto &v: u) {
      scanf("%lld", &v);
    }
  }
  auto Fun = [&](int i, int j, int k, int l) {
    return a[i][l] + a[j][l] + a[k][l];
  };
  i64 res = 0;
  for (int r1 = 0; r1 < n; ++r1) {
    for (int r2 = r1 + 1; r2 < n; ++r2) {
      for (int r3 = r2 + 1; r3 < n; ++r3) {
        i64 mx1 = 0, mx2 = 0;
        for (int c1 = 0; c1 < m; ++c1) {
          if (mx1 < Fun(r1, r2, r3, c1)) {
            mx2 = mx1;
            mx1 = Fun(r1, r2, r3, c1);
          } else if (mx2 < Fun(r1, r2, r3, c1)) {
            mx2 = Fun(r1, r2, r3, c1);
          }
        }
        res = std::max(res, mx1 + mx2);
      }
    }
  }
  printf("%lld\n", res);
  return 0;
}
