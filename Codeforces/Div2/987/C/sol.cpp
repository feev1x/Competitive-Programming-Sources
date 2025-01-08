/**
 *    author:  feev1x
 *    created: 15.11.2024 19:05:12
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    if (n & 1) {
      if (n < 27) {
        printf("-1\n");
      } else {
        printf("1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 10 13 9 9 10 11 11 12 12 1 13 ");
        n -= 27;
        for (int i = 1; i <= n / 2; ++i) {
          printf("%d %d ", i + 13, i + 13);
        }
        printf("\n");
      }
    } else {
      for (int i = 1; i <= n / 2; ++i) {
        printf("%d %d ", i, i);
      }
      printf("\n");
    }
  }
  return 0;
}
