/**
 *    author:  feev1x
 *    created: 17.10.2024 22:40:40
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  a.insert(a.begin(), 0);
  vector<vector<int64_t>> dp(n + 2, vector<int64_t>(n + 2)), sum(n + 1, vector<int64_t>(n + 1));
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      if (l == r) {
        sum[l][r] = a[l];
      } else {
        sum[l][r] = sum[l][r - 1] + a[r];
      }
    }
  }
  auto chmin = [](int64_t &a, int64_t b) {
    if (a > b) {
      a = b;
    }
  };
  for (int l = n; l >= 1; --l) {
    for (int r = l; r <= n; ++r) {
      if (l == r) {
        dp[l][r] = 0;
        continue;
      }
      dp[l][r] = 1e18;
      for (int i = 1; i <= n; ++i) {
        if (l + i <= r) {
          chmin(dp[l][r], dp[l + i][r] + dp[l][l + i - 1] + sum[l][r]);
        }
        if (r - i >= l) {
          chmin(dp[l][r], dp[l][r - i] + dp[r - i + 1][r] + sum[l][r]);
        }
      }
      debug(l, r, dp[l][r], sum[l][r]);
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}
