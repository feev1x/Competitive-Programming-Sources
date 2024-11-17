/**
 *    author:  feev1x
 *    created: 16.11.2024 13:15:58
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  printf("%d\n", res);
  return 0;
}
