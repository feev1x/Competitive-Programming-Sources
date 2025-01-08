/**
 *    author:  feev1x
 *    created: 15.11.2024 18:36:26
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      if (v.empty() || v.back().first != a[i]) {
        v.emplace_back(a[i], 1);
      } else {
        int cnt = v.back().second;
        v.pop_back();
        v.emplace_back(a[i], cnt + 1);
      }
    }
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
      res = std::max(res, v[i].second);
    }
    printf("%d\n", n - res);
  }
  return 0;
}
