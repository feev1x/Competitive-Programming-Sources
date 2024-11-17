/**
 *    author:  feev1x
 *    created: 14.11.2024 13:39:41
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<std::pair<double, double>> sm(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &sm[i].first, &sm[i].second);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto [x1, y1] = sm[i];
      auto [x2, y2] = sm[j];
      double slp = abs(y1 - y2) / abs(x1 - x2);

    }
  }
  return 0;
}
