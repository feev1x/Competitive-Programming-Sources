/**
 *    author:  feev1x
 *    created: 14.11.2024 13:25:31
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> a(n), b(n);
  std::vector<std::pair<i64, i64>> mn(n), mx(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &b[i]);
  }
  return 0;
}
