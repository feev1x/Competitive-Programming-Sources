/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t 
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e18));
  auto chmin = [](int &a, int b) {
    if (a > b) {
      a = b;
    }
  };
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int u; cin >> u;
    for (int a = 1; a <= 100; ++a) {
      for (int area = 0; area <= m; ++area) {
        if (dp[i][area] == 1e18) continue;
        if (area + a * a <= m) {
          chmin(dp[i + 1][area + a * a], dp[i][area] + (a - u) * (a - u));
        }
      }
    }
  }
  if (dp[n][m] == 1e18) dp[n][m] = -1;
  cout << dp[n][m] << '\n';
}

