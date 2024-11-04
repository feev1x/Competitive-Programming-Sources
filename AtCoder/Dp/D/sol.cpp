/**
 *    author:  feev1x
 *    created: 14.10.2024 13:52:31
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, W; cin >> n >> W;
  vector<int64_t> dp(W + 1);
  for (int i = 0; i < n; ++i) {
    int w, v; cin >> w >> v;
    for (int i = W; i >= w; --i) {
      dp[i] = max(dp[i], dp[i - w] + v);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}
