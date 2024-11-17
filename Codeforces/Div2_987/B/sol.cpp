/**
 *    author:  feev1x
 *    created: 15.11.2024 18:51:26
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      pos[p[i]] = i;
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
      if (std::abs(pos[i] - i) > 2) {
        flag = false;
        break;
      }
      int ps = pos[i], dif = std::abs(pos[i] - i);
      if (!dif) continue;
      if (pos[i] < i) {
        if (std::abs(i - p[ps + 1]) > 1 || dif == 2 && std::abs(i - p[ps + 2]) > 1) {
          flag = false;
          break;
        }
      } else {
        if (std::abs(i - p[ps - 1]) > 1 || dif == 2 && std::abs(i - p[ps - 2]) > 1) {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
