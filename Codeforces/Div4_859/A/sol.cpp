/**
 *    author:  feev1x
 *    created: 15.12.2024 01:16:11
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    printf(a + b == c ? "+\n" : "-\n");
  }
  return 0;
}
