/**
 *    author:  feev1x
 *    created: 30.11.2024 18:06:03
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  std::sort(a.begin(), a.end());
  std::vector<int> mn(n + 1);
  mn[0] = a[0].second;
  for (int i = 1; i < n; ++i) {
    mn[i] = std::min(mn[i - 1], a[i].second);
  }
  for (int i = 0; i < m; ++i) {
    int u; scanf("%d", &u);
    int j = std::upper_bound(a.begin(), a.end(), std::pair{u, n + 1}) - a.begin();
    --j;
    if (j == -1) {
      printf("-1\n");
    } else {
      printf("%d\n", mn[j]);
    }
  }
  return 0;
}
