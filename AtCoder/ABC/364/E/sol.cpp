/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y; cin >> n >> x >> y;
  vector<vector<vector<int64_t>>> dp(n + 1, vector<vector<int64_t>>(n + 1, vector<int64_t>(x + 1, 1e9)));
  auto chmax = [](int64_t &a, int64_t b) {
    if (a < b) {
      a = b;
      return true;
    }
    return false;
  };
  auto chmin = [](int64_t &a, int64_t b) {
    if (a > b) {
      a = b;
      return true;
    }
    return false;
  };
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int64_t a, b; cin >> a >> b;
    for (int j = 0; j <= i; ++j) {
      for (int sw = 0; sw <= x; ++sw) {
        if (sw >= a && j) {
          chmin(dp[i][j][sw], dp[i - 1][j - 1][sw - a] + b);
        }
        chmin(dp[i][j][sw], dp[i - 1][j][sw]);
      }
    }
  }
  int res = 0;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= x; ++j) {
      if (dp[n][i][j] <= y) {
        res = i;
        goto exit;
      }
    }
  }
exit:
  cout << min(res + 1, n) << '\n';
}

