/**
 *    author:  feev1x
 *    created: 16.11.2024 13:06:59
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int a, b, n; scanf("%d%d%d", &a, &b, &n);
  int mon = b + a * 100;
  mon *= n;
  a = mon / 100, b = mon % 100;
  printf("%d %d\n", a, b);
  return 0;
}
