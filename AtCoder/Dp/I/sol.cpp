/**
 *    author:  feev1x
 *    created: 14.10.2024 14:29:51
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    double h; cin >> h;
    double t = 1 - h;
    for (int j = 0; j < i; ++j) {
      dp[j + 1][i - j - 1] += dp[j][i - j - 1] * h;
      dp[j][i - j] += dp[j][i - j - 1] * t;
    }
  }
  double res = 0;
  for (int j = n / 2 + 1; j <= n; ++j) {
    res += dp[j][n - j];
  }
  cout << fixed << setprecision(10) << res << '\n';
}
