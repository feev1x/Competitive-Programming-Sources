/**
 *    author:  feev1x
 *    created: 13.11.2024 11:35:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("j.in", "r", stdin);
  std::freopen("j.out", "w", stdout);
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  std::vector<int> a(n + 1), b(m + 1);
  std::vector<std::array<int, 21>> pa(n + 1), pb(m + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 0; j < 21; ++j) {
      pa[i][j] = pa[i - 1][j] + bool(a[i] & 1 << j);
    }
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    for (int j = 0; j < 21; ++j) {
      pb[i][j] = pb[i - 1][j] + bool(b[i] & 1 << j);
    }
  }
  while (k--) {
    int u, l, d, r; scanf("%d%d%d%d", &u, &l, &d, &r);
    i64 res = 0;
    for (i64 i = 0; i < 21; ++i) {
      i64 cnt1 = pa[d][i] - pa[u - 1][i];
      i64 cnt2 = pb[r][i] - pb[l - 1][i];
      res += (cnt1 * cnt2) * (1ll << i);
    }
    printf("%lld\n", res);
  }
  return 0;
}
