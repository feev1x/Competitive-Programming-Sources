/**
 *    author:  feev1x
 *    created: 17.10.2024 22:26:32
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
  int n, k; cin >> n >> k;
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(k + 1)), p(n + 1, vector<int64_t>(k + 1));
  dp[0][0] = 1;
  for (int i = 0; i <= k; ++i) {
    p[0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    for (int j = 0; j <= k; ++j) {
      dp[i][j] += p[i - 1][j] - p[i - 1][max(0, j - u)] + dp[i - 1][max(0, j - u)];
      dp[i][j] %= mod;
      if (j) {
        p[i][j] = dp[i][j] + p[i][j - 1];
      }
    }
  }
  cout << dp[n][k] << '\n';
  return 0;
}
