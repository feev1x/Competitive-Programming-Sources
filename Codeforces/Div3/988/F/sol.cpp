/**
 *    author:  feev1x
 *    created: 17.11.2024 21:50:10
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    std::vector<int> h(n), x(n);
    for (auto &u: h) {
      scanf("%d", &u);
    }
    for (auto &u: x) {
      scanf("%d", &u);
    }
    int temp = x.front() + x.back() >> 1;
    auto Dis = [](int x1, int x2) {
      return x1 > x2 ? x1 - x2 : x2 - x1;
    };
    if (Dis(temp, x.front()) >= m || Dis(temp, x.back()) >= m) {
      printf("-1\n");
      continue;
    }
    printf("1\n");
  }
  return 0;
}
