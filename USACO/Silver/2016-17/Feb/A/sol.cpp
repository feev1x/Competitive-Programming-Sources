/**
 *    author:  feev1x
 *    created: 04.12.2024 11:26:32
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("helpcross.in", "r", stdin);
  std::freopen("helpcross.out", "w", stdout);
  int c, n; scanf("%d%d", &c, &n);
  std::vector<int> t(c), a(n), b(n);
  for (auto &u: t) {
    scanf("%d", &u);
  }
  std::sort(t.begin(), t.end());
  std::vector<int> ind;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    int j = std::lower_bound(t.begin(), t.end(), a[i]) - t.begin();
    a[i] = j;
    j = std::upper_bound(t.begin(), t.end(), b[i]) - t.begin();
    b[i] = j - 1;
    ind.emplace_back(i);
  }
  std::sort(ind.begin(), ind.end(), [&](int i, int j) {
      return b[i] < b[j];
      });
  std::vector<bool> used(c);
  int cnt = 0;
  for (auto i: ind) {
    for (int pos = a[i]; pos <= b[i]; ++pos) {
      if (!used[pos]) {
        cnt++;
        used[pos] = true;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
