/**
 *    author:  feev1x
 *    created: 16.11.2024 13:01:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int h1, m1, s1, h2, m2, s2; scanf("%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2);
  int sec1 = 3600 * h1 + 60 * m1 + s1;
  int sec2 = 3600 * h2 + 60 * m2 + s2;
  printf("%d\n", (int)std::abs(sec1 - sec2));
  return 0;
}
