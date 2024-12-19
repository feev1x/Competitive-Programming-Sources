/**
 *    author:  feev1x
 *    created: 15.12.2024 00:52:20
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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      a[i] += a[i - 1];
    }
    auto Ask = [&](int l, int r) {
      printf("? %d ", r - l + 1);
      for (int i = l; i <= r; ++i) {
        printf("%d ", i);
      }
      printf("\n");
      fflush(stdout);
      int got; scanf("%d", &got);
      return got;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r) {
      int m = l + r >> 1;
      if (Ask(l, m) == a[m] - a[l - 1]) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    printf("! %d\n", ans);
    fflush(stdout);
  }
  return 0;
}
