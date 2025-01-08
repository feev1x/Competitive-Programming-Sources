/**
 *    author:  feev1x
 *    created: 30.11.2024 19:12:00
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int k, x1, y1, x2, y2; scanf("%d%d%d%d%d", &k, &x1, &y1, &x2, &y2);
    if (y1 < y2) {
      std::swap(x1, x2);
      std::swap(y1, y2);
    }

  }
  return 0;
}
