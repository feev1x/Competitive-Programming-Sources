/**
 *    author:  feev1x
 *    created: 15.12.2024 20:40:14
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int m, a, b, c; scanf("%d%d%d%d", &m, &a, &b, &c);
    a = std::min(a, m);
    b = std::min(b, m);
    int cnt = 2 * m - a - b - c;
    if (cnt < 0) {
      cnt = 0;
    }
    printf("%d\n", 2 * m - cnt);
  }
  return 0;
}
