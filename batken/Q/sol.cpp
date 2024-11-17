/**
 *    author:  feev1x
 *    created: 16.11.2024 12:30:48
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    auto Check = [&](int j) {
      if (j + 1 > n || j < 1) return false;
      return a[j] == a[j + 1];
    };
    int res = INF;
    for (int ite = 0; ite < 100; ++ite) {
      for (int i = 1; i <= n / 2; ++i) {
        if (a[i] == a[i - 1]) {
          std::swap(a[i], a[n - i + 1]);
        }
      }
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        ans += Check(i);
      }
      res = std::min(res, ans);
      ans = 0;
      for (int i = n / 2 + 1; i + 1 <= n; ++i) {
        if (a[i] == a[i + 1]) {
          std::swap(a[i], a[n - i + 1]);
        }
      }
      for (int i = 1; i <= n; ++i) {
        ans += Check(i);
      }
      res = std::min(res, ans);
    }
    printf("%d\n", res);
  }
  return 0;
}
