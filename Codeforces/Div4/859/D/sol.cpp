/**
 *    author:  feev1x
 *    created: 15.12.2024 00:58:31
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, q; scanf("%d%d", &n, &q);
    std::vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
      sum %= 2;
      a[i] += a[i - 1];
      a[i] %= 2;
    }
    while (q--) {
      int l, r, k; scanf("%d%d%d", &l, &r, &k);
      int sm = (i64)k * (r - l + 1) % 2;
      bool flag = false;
      if (sm == (a[r] ^ a[l - 1])) {
        flag = sum;
      } else {
        flag = !sum;
      }
      printf(flag ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
