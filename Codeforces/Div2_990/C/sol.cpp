/**
 *    author:  feev1x
 *    created: 03.12.2024 12:59:21
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e15;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<std::pair<i64, i64>> a(n);
    for (auto &u: a) {
      scanf("%lld", &u.first);
    }
    for (auto &u: a) {
      scanf("%lld", &u.second);
    }
    std::sort(a.begin(), a.end(), [](std::pair<i64, i64> x, std::pair<i64, i64> y) {
        return x.first - x.second > y.first - y.second;
        });
    i64 res = -INF;
    for (int i = 0; i < n; ++i) {
      i64 ans = 0, mx1 = -INF, mx2 = -INF;
      for (int j = 0; j < n; ++j) {
        if (j <= i) {
          ans += a[j].first;
          mx1 = std::max(mx1, a[j].second);
        }
        if (j >= i) {
          ans += a[j].second;
          mx2 = std::max(mx2, a[j].first);
        }
      }
      res = std::max({res, ans, ans - a[i].second + mx1, ans - a[i].first + mx2});
    }
    printf("%lld\n", res);
  }
  return 0;
}
