/**
 *    author:  feev1x
 *    created: 11.11.2024 20:30:50
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  if (n > m) {
    std::swap(n, m);
  }
  std::vector dp(m + 1, std::vector<int>(1 << n));
  for (int i = 0; i < 1 << n; ++i) {
    dp[1][i] = 1;
  }
  auto Check = [&](int mask1, int mask2) {
    debug(mask1, mask2);
    for (int i = 0; i + 1 < n; ++i) {
      int cnt = (mask1 & 1 << i) == (mask2 & 1 << i);
      cnt += (mask1 & 1 << i + 1) == (mask2 & 1 << i + 1);
      cnt += bool(mask1 & 1 << i) == bool(mask1 & 1 << i + 1);
      if (cnt == 3) {
        return false;
      }
    }
    return true;
  };
  for (int i = 2; i <= m; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      for (int k = 0; k < 1 << n; ++k) {
        if (Check(j, k)) {
          dp[i][j] += dp[i - 1][k];
        }
      }
    }
  }
  int sum = accumulate(dp[m].begin(), dp[m].end(), 0);
  printf("%d\n", sum);
  return 0;
}
