/**
 *    author:  feev1x
 *    created: 02.12.2024 20:36:29
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    std::vector<int> a(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    int sum = 0;
    for (auto u: a) {
      if (sum + u > k) {
        break;
      }
      sum += u;
    }
    printf("%d\n", k - sum);
  }
  return 0;
}
