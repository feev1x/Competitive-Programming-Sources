/**
 *    author:  feev1x
 *    created: 03.12.2024 12:26:28
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    int num = 1, cnt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      cnt += u;
      while (cnt > num * num) {
        num += 2;
      }
      if (cnt == num * num) {
        res++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
