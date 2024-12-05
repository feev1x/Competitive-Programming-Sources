/**
 *    author:  feev1x
 *    created: 29.11.2024 23:18:32
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("div7.in", "r", stdin);
  std::freopen("div7.out", "w", stdout);
  int n, res = 0; scanf("%d", &n);
  std::vector<int> a(n), p(n);
  std::array<int, 7> mx{};
  std::fill(mx.begin(), mx.end(), -1);
  for (auto &u: a) {
    scanf("%d", &u);
    u %= 7;
    if (u == 0) {
      res = 1;
    }
  }
  p[0] = a[0];
  mx[p[0]] = 0;
  for (int i = 1; i < n; ++i) {
    p[i] = (p[i - 1] + a[i]) % 7;
    mx[p[i]] = i;
  }
  res = std::max(res, mx[0]);
  for (int i = 0; i < n; ++i) {
    res = std::max(res, mx[p[i]] - i);
  }
  printf("%d\n", res);
  return 0;
}
