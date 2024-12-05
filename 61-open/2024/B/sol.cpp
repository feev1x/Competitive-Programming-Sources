/**
 *    author:  feev1x
 *    created: 24.11.2024 10:07:17
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  long double tm = 1 / (long double)m;
  if (std::fmod((long double)n * tm, 1) == 0.5 || std::fmod((long double)n * tm, 1) == 0) {
    printf("0\n");
  } else if (std::fmod(n * tm, 1) > 0.5) {
    printf("-1\n");
  } else {
    printf("1\n");
  }
  return 0;
}
