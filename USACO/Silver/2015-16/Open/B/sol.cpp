/**
 *    author:  feev1x
 *    created: 02.12.2024 18:35:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("diamond.in", "r", stdin);
  std::freopen("diamond.out", "w", stdout);
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  std::sort(a.begin(), a.end());
  int res = 0;
  std::vector<int> mx(n);
  for (int i = 0; i < n; ++i) {
    int j = std::lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();
    mx[i] = std::max(mx[i ? i - 1 : 0], i - j + 1);
  }
  for (int i = 0; i < n; ++i) {
    int j = std::upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
    res = std::max(res, j - i + mx[i ? i - 1 : 0]);
  }
  printf("%d\n", res);
  return 0;
}
