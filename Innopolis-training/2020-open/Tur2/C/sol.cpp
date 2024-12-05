/**
 *    author:  feev1x
 *    created: 21.11.2024 14:03:45
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> a(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  std::sort(a.begin(), a.end(), std::greater<>());
  int m; scanf("%d", &m);
  std::vector<std::pair<i64, i64>> cb(m);
  for (int i = 0; i < m; ++i) {
    scanf("%lld%lld", &cb[i].first, &cb[i].second);
  }
  std::sort(cb.begin(), cb.end(), [](std::pair
  int qr; scanf("%d", &qr);
  while (qr--) {
    int d; scanf("%d", &d);
    i64 res = 0; 
    std::vector<std::pair<i64, i64>> cc;
    for (int i = 0; i < n; ++i) {
      cc.emplace_back(0, i);
    }
    for (int i = 0; i < m; ++i) {
      cc.emplace_back(1, i);
    }
    do {
      i64 fol = 1e4, ans = 0, cnt = 0;
      for (auto [tp, i]: cc) {
        if (cnt == d) break;
        if (tp == 0) {
          fol += a[i];
        } else {
          ans += fol * c[i];
          fol -= b[i];
        }
        cnt++;
      }
      res = std::max(res, ans);
    } while (std::next_permutation(cc.begin(), cc.end()));
    printf("%lld\n", res);
  }
  return 0;
}
