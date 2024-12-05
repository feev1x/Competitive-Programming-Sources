/**
 *    author:  feev1x
 *    created: 04.12.2024 13:29:52
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("pairup.in", "r", stdin);
  std::freopen("pairup.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<std::pair<int, int>> cows(n);
  for (auto &[x, y]: cows) {
    scanf("%d%d", &y, &x);
  }
  std::sort(cows.begin(), cows.end());
  int i = 0, j = n - 1, mx = 0;
  while (i <= j) {
    int mn = std::min(cows[i].second, cows[j].second);
    mx = std::max(mx, cows[i].first + cows[j].first);
    cows[i].second -= mn;
    if (i != j) {
      cows[j].second -= mn;
    }
    if (cows[i].second == 0) {
      ++i;
    }
    if (cows[j].second == 0) {
      --j;
    }
  }
  printf("%d\n", mx);
  return 0;
}
