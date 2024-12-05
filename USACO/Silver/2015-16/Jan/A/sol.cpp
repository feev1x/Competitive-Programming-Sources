/**
 *    author:  feev1x
 *    created: 29.11.2024 23:12:14
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("angry.in", "r", stdin);
  std::freopen("angry.out", "w", stdout);
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> x(n);
  for (auto &u: x) {
    scanf("%d", &u);
  }
  std::sort(x.begin(), x.end());
  int l = 0, r = 1e9, ans = 1e9;
  while (l <= r) {
    int m = l + r >> 1, cnt = 1;
    for (int i = 0, j = 0; i < n; ++i) {
      if (x[i] - x[j] > 2 * m) {
        j = i;
        cnt++;
      }
    }
    if (cnt > k) {
      l = m + 1;
    } else {
      r = m - 1;
      ans = m;
    }
  }
  printf("%d\n", ans);
  return 0;
}
