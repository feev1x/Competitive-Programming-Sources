/**
 *    author:  feev1x
 *    created: 14.10.2024 13:46:10
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> dp(3, vector<int>(n + 1));
  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[2][0] = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, c; cin >> a >> b >> c;
    dp[0][i + 1] = max(dp[0][i + 1], a + max(dp[1][i], dp[2][i]));
    dp[1][i + 1] = max(dp[1][i + 1], b + max(dp[0][i], dp[2][i]));
    dp[2][i + 1] = max(dp[2][i + 1], c + max(dp[1][i], dp[0][i]));
  }
  cout << max({dp[0][n], dp[1][n], dp[2][n]}) << '\n';
}
