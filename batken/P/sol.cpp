/**
 *    author:  feev1x
 *    created: 16.11.2024 12:41:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    i64 a[n][n];
    std::map<i64, i64> mp;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%lld", &a[i][j]);
        if (a[i][j] < 0) {
          mp[i - j] = std::max(mp[i - j], -a[i][j]);
        }
      }
    }
    i64 res = 0;
    for (auto [key, val]: mp) {
      res += val;
    }
    printf("%lld\n", res);
  }
  return 0;
}
