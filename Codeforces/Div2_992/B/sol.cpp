/**
 *    author:  feev1x
 *    created: 08.12.2024 20:40:08
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    int res = 1;
    for (int i = 1; i < n;) {
      i += i + 2;
      res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
