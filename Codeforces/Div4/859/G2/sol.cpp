/**
 *    author:  feev1x
 *    created: 15.12.2024 00:27:17
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
    std::vector<i64> c(n);
    for (auto &u: c) {
      scanf("%d", &u);
    }
    std::sort(c.begin(), c.end());
    if (c[0] != 1) {
      printf("NO\n");
      continue;
    }
    bool flag = true;
    i64 mx = 1;
    for (int i = 1; i < n; ++i) {
      if (mx < c[i]) {
        flag = false;
        break;
      }
      mx += c[i];
    }
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}
