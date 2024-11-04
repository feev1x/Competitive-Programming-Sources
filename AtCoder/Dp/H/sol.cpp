/**
 *    author:  feev1x
 *    created: 14.10.2024 14:24:50
**/
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w; cin >> h >> w;
  vector<vector<int64_t>> dp(h + 2, vector<int64_t>(w + 2));
  dp[0][1] = 1;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      char c; cin >> c;
      if (c == '.') {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
      }
    }
  }
  cout << dp[h][w] << '\n';
}
