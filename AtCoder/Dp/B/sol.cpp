/**
 *    author:  feev1x
 *    created: 14.10.2024 13:44:06
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> h(n), dp(n, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    for (int j = 1; j <= min(i, k); ++j) {
      dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n - 1] << '\n';
}
