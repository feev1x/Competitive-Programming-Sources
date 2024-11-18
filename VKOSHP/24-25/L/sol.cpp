/**
 *    author:  feev1x
 *    created: 17.11.2024 19:35:09
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  if (n == 1) {
    printf("1\n");
  } else if (n == 5) {
    printf("4 4 2 2 2\n4 4 4 2 3\n5 5 1 2 3\n5 1 1 3 3\n5 5 1 1 3\n");
  } else if (n > 5) {
    int cnt = 1;
    int a[n + 1][n + 1]{};
    for (int i = 1; i <= n; ++i) {
      a[i][n] = cnt;
    }
    cnt++;
    int tc = 1, nw = 1;
    for (; cnt <= n / 2 + 1; ++cnt) {
      for (int j = n - 1; j >= 1; --j) {
        if (a[nw][j] == 0) {
          a[nw][j] = cnt;
        }
        if (j == tc) {
          nw++;
          a[nw][j] = cnt;
          tc++;
        }
      }
    }
    int y = n / 2 + 1;
    int x = n - 1;
    int kn = n;
    int ot = n / 2;
    if (n % 2 == 0) ot--;
    for (; cnt <= n; ++cnt) {
      for (int i = y; i <= kn; ++i) {
        a[i][x] = cnt;
      }
      for (int j = x; j >= ot; --j) {
        a[kn][j] = cnt;
      }
      for (int i = kn; i <= n; ++i) {
        a[i][ot] = cnt;
      }
      x--;
      kn--;
      ot--;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
