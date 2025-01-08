/**
 *    author:  feev1x
 *    created: 17.11.2024 22:36:23
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    if (n <= 4) {
      printf("-1\n");
      continue;
    }
    for (int i = 1; i <= n; i += 2) {
      if (i != 5) {
        printf("%d ", i);
      }
    }
    printf("5 4 ");
    for (int i = 2; i <= n; i += 2) {
      if (i != 4) {
        printf("%d ", i);
      }
    }
    printf("\n");
  }
  return 0;
}
