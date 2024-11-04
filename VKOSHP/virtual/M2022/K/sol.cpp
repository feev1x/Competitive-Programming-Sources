/**
 *    author:  feev1x
 *    created: 18.10.2024 12:09:15
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto Modm = [&](int64_t a, int64_t b) {
    return (a * b) % mod;
  };
  auto Modp = [&](int64_t a, int64_t b) {
    return (a + b) % mod;
  };
  int64_t n; cin >> n;
  vector<int64_t> inv(n + 1), dp(n + 1);
  dp[0] = dp[1] = 1;
  inv[0] = inv[1] = 0;
  for (int64_t i = 1; i <= n; ++i) {
    dp[i] = Modp(dp[i - 1], Modm(dp[i - 2], i - 1));
    inv[i] = Modp(inv[i - 1], Modp(Modm(i - 1, inv[i - 2]), Modm(dp[i - 2], (i * (i - 1)) / 2 % mod)));
  }
  cout << dp[n] << ' ' << inv[n] << '\n';
  return 0;
}
