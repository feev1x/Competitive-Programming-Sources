/**
 *    author:  feev1x
 *    created: 09.12.2024 09:19:10
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 n; scanf("%lld", &n);  
  if (n == 3) {
    printf("1\n");
    exit(0);
  }
  i64 res = ((n / 2) / 2) * n;
  if (n & 1) {
    if (n % 3 == 0) {
      res += n / 3 + n * ((n / 2 + 1) / 2 - 1);
    } else {
      res += n * ((n / 2 + 1) / 2);
    }
  } else {
    if (n % 3 == 0) {
      res += n / 3 + n * (n / 2 / 2 - 1);
    } else {
      res += n * (n / 2 / 2 - 1);
    }
  }
  printf("%lld\n", res);
  return 0;
}
