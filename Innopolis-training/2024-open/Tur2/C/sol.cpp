/**
 *    author:  feev1x
 *    created: 18.11.2024 15:24:09
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector t(n + 1, std::vector<i64>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%lld", &t[i][j]);
    }
  }
  i64 res = 0;
  std::vector cnt_a(n + 1, std::vector<i64>(m + 1)), cnt_b(n + 1, std::vector<i64>(m + 1));
  for (int i = 1; i <= n; ++i) {
    std::map<i64, i64> cnt;
    for (int j = m; j >= 1; --j) {
      cnt_b[i][j] = cnt[t[i][j] + j]++;
    }
  }
  for (int j = 1; j <= m; ++j) {
    std::map<i64, i64> cnt;
    for (int i = n; i >= 1; --i) {
      cnt_a[i][j] = cnt[t[i][j] + i]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      res += cnt_a[i][j] * cnt_b[i][j];
    }
  }
  printf("%lld\n", res);
  return 0;
}
