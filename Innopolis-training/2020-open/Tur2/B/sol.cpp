/**
 *    author:  feev1x
 *    created: 21.11.2024 13:36:48
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9 + 7;

int main() {
  int n; scanf("%d", &n);
  while (n--) {
    int l1, r1, l2, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    int s1, d1, s2, d2; scanf("%d%d%d%d", &s1, &d1, &s2, &d2);
    if (s1 + d1 <= s2 || s2 + d2 <= s1) {
      printf("%d %d\n", s1, s2);
      continue;
    }
    int ps1 = r2 - d2 - 1;
    if (s1 < ps1 - d1 + 1) {
      ps1 = s1 + d1 - 1;
    }
    int res = INF, c1 = -1, c2 = -1;
    if (l1 <= ps1 - d1 + 1 && ps1 + 1 <= r1) {
      int ps2 = ps1 + 1;
      if (s2 > ps2) {
        ps2 = s2;
      }
      if (l2 <= ps2 && ps2 + d2 <= r2) {
        if (res > ps2 - s2 + s1 - (ps1 - d1 + 1)) {
          res = ps2 - s2 + s1 - (ps1 - d1 + 1);
          c1 = ps1 - d1 + 1;
          c2 = ps2;
        }
      }
    }
    int ps2 = r1 - d1 - 1;
    if (s2 < ps2 - d2 + 1) {
      ps2 = s2 + d2 - 1;
    }
    if (l2 <= ps2 - d2 + 1 && ps2 + 1 <= r2) {
      int ps1 = ps2 + 1;
      if (s1 > ps1) {
        ps1 = s1;
      }
      if (l1 <= ps1 && ps1 + d1 <= r1) {
        if (res > ps1 - s1 + s2 - (ps2 - d2 + 1)) {
          res = ps1 - s1 + s2 - (ps2 - d2 + 1);
          c2 = ps2 - d2 + 1;
          c1 = ps1;
        }
      }
    }
    printf("%d %d\n", c1, c2);
  }
  return 0;
}
