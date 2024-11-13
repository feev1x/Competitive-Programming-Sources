/**
 *    author:  feev1x
 *    created: 13.11.2024 08:20:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, k; i64 m; scanf("%d%lld%d", &n, &m, &k);
  std::vector<i64> a(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  std::sort(a.begin(), a.end());
  int sz = 0, mn = -1, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (mn == -1 || a[i] - mn > m || sz + 1 > k) {
      sz = 1;
      mn = a[i];
      cnt++;
    } else {
      sz++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
