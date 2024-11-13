/**
 *    author:  feev1x
 *    created: 13.11.2024 08:09:15
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> a(n);
  i64 res = 1e18, sum = 0;
  for (auto &u: a) {
    scanf("%lld", &u);
    sum += u;
    std::cerr << sum << '\n';
    res = std::min(res, sum);
  }
  printf("%lld\n", std::max(0ll, -res));
  return 0;
}
