/**
 *    author:  feev1x
 *    created: 08.12.2024 20:35:37
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
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      bool check = true;
      for (int j = 0; j < n; ++j) {
        if (j == i) {
          continue;
        }
        if (std::abs(a[i] - a[j]) % k == 0) {
          check = false;
          break;
        }
      }
      if (check) {
        ans = i + 1;
        break;
      }
    }
    if (ans == -1) {
      printf("NO\n");
    } else {
      printf("YES\n%d\n", ans);
    }
  }
  return 0;
}
