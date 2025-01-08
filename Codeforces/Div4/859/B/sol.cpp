/**
 *    author:  feev1x
 *    created: 15.12.2024 01:14:36
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    int sum[2]{};
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      sum[u % 2] += u;
    }
    printf(sum[0] > sum[1] ? "YES\n" : "NO\n");
  }
  return 0;
}
