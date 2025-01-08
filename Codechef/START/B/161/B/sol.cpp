/**
 *    author:  feev1x
 *    created: 20.11.2024 20:39:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> p(n + 1);
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      if (p[i] == i) {
        flag = true;
      }
    }
    if (std::is_sorted(p.begin(), p.end())) {
      printf("%d\n", n);
    } else if (flag) {
      printf("%d\n", n - 1);
    } else {
      printf("%d\n", n - 2);
    }
  }
  return 0;
}
