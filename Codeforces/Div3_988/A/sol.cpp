/**
 *    author:  feev1x
 *    created: 17.11.2024 22:46:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      mp[u]++;
    }
    int res = 0;
    for (auto [key, val]: mp) {
      res += val / 2;
    }
    printf("%d\n", res);
  }
  return 0;
}
