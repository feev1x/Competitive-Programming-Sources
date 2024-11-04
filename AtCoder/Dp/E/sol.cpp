/**
 *    author:  feev1x
 *    created: 14.10.2024 13:57:44
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int64_t W; cin >> n >> W;
  vector<int64_t> dp(100001, 1e9 + 1);
  dp[0] = 0;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int64_t w; cin >> w;
    int v; cin >> v;
    for (int i = 1e5; i >= v; --i) {
      if (dp[i - v] == 1e9 + 1) continue;
      dp[i] = min(dp[i], dp[i - v] + w);
      if (dp[i] <= W) mx = max(mx, i);
    }
  }
  cout << mx << '\n';
}
