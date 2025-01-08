/**
 *    author:  feev1x
 *    created: 15.12.2024 21:08:29
**/
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

constexpr int N = 2e5 + 5;

int main() {
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  std::vector<i64> a(n), b(m);
  std::map<i64, bool> mp1, mp2;
  i64 sum1 = 0, sum2 = 0;
  for (auto &u: a) {
    scanf("%lld", &u);
    sum1 += u;
  }
  for (auto &u: b) {
    scanf("%lld", &u);
    sum2 += u;
  }
  for (int i = 0; i < n; ++i) {
    mp1[sum1 - a[i]] = true;
  }
  for (int i = 0; i < m; ++i) {
    mp2[sum2 - b[i]] = true;
  }
  std::map<int, bool> used, flag;
  while (q--) {
    int x; scanf("%d", &x);
    if (used[x]) {
      printf(flag[x] ? "YES\n" : "NO\n");
      continue;
    }
    used[x] = true;
    for (int i = 1; i * i <= std::abs(x); ++i) {
      if (x % i == 0 && ((mp1[i] & mp2[x / i]) || (mp2[i] & mp1[x / i]))) {
        flag[x] = true;
        break;
      }
      i = -i;
      if (x % i == 0 && ((mp1[i] & mp2[x / i]) || (mp2[i] & mp1[x / i]))) {
        flag[x] = true;
        break;
      }
      i = -i;
    }
    printf(flag[x] ? "YES\n" : "NO\n");
  }
  return 0;
}
