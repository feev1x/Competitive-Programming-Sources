/**
 *    author:  feev1x
 *    created: 29.11.2024 23:03:59
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("bcount.in", "r", stdin);
  std::freopen("bcount.out", "w", stdout);
  int n, q; scanf("%d%d", &n, &q);
  std::vector<std::array<int, 3>> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1];
    int u; scanf("%d", &u); u--;
    p[i][u]++;
  }
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    printf("%d %d %d\n", p[r][0] - p[l - 1][0], p[r][1] - p[l - 1][1], p[r][2] - p[l - 1][2]);
  }
  return 0;
}
