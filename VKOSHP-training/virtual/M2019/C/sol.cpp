/**
 *    author:  feev1x
 *    created: 12.11.2024 09:36:20
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

const int MOD = 1e9 + 7;

int main() {
  i64 n, m; scanf("%lld%lld", &n, &m);
  if (n < m) {
    std::swap(n, m);
  }
  std::vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }
  printf("%d\n", (((dp[n] * 2) % MOD + (dp[m] * 2) % MOD) % MOD -  2 + MOD) % MOD);
  return 0;
}
