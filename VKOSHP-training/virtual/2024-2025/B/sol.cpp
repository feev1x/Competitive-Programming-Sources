/**
 *    author:  feev1x
 *    created: 10.12.2024 09:01:16
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
    if (b > y || a > x) {
      printf("-1\n");
      continue;
    }
    if (b == 0) {
      if (y >= x) {
        printf("-1\n");
        continue;
      }
      int mx = y + 1;
      x -= mx;
      if (x < a - 1) {
        printf("-1\n");
        continue;
      }
      x -= a - 1;
      mx += x;
      printf("%d\n", x);
      continue;
    } else if (a == 0) {
      if (x >= y) {
        printf("-1\n");
        continue;
      }
      int mx = x;
      y -= mx + 1;
      if (y < b - 1) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", mx);
    } else {
      x -= a, y -= b;
      printf("%d\n", x + 1);
    }
  }
  return 0;
}
