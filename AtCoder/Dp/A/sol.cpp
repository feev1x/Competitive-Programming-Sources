/**
 *    author:  feev1x
 *    created: 14.10.2024 13:40:46
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> h(n), dp(n, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    if (i) {
      dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
      if (i - 1) {
        dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
      }
    }
  }
  cout << dp[n - 1] << '\n';
}
