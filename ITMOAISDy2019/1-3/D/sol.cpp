/**
 *    author:  feev1x
 *    created: 10.11.2024 17:34:32
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

const int mod = 1e9;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int main() {
  int n; scanf("%d", &n);
  std::vector<std::array<int, 10>> dp(n + 1);
  for (int i = 1; i < 10; ++i) {
    dp[1][i] = 1;
  }
  std::array<std::vector<int>, 10> mov;
  mov[0] = {4, 6};
  mov[1] = {8, 6};
  mov[2] = {7, 9};
  mov[3] = {4, 8};
  mov[4] = {0, 9, 3};
  mov[5] = {};
  mov[6] = {1, 7, 0};
  mov[7] = {6, 2};
  mov[8] = {1, 3};
  mov[9] = {4, 2};
  dp[1][8] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (auto u: mov[j]) {
        add_self(dp[i][j], dp[i - 1][u]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 10; ++i) {
    add_self(res, dp[n][i]);
  }
  printf("%d\n", res);
  return 0;
}
