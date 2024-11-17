/**
 *    author:  feev1x
 *    created: 16.11.2024 13:03:24
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  int h = n / 3600 % 24;
  n %= 3600;
  int m = n / 60 % 60;
  n %= 60;
  int s = n;
  printf("%d:%d%d:%d%d\n", h, m / 10, m % 10, s / 10, s % 10);
  return 0;
}
