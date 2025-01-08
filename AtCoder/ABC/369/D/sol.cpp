/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

int64_t mx[2];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<int64_t>> dp(n, vector<int64_t>(2));
  for (int i = 0; i < n; ++i) {
    int u; cin >> u;
    for (int j = 0; j < 2; ++j) {
      if (i == 0 && j == 1) continue;
      dp[i][j] = mx[(j + 1) % 2] + u * (j + 1);
    }
    for (int j = 0; j < 2; ++j) {
      mx[j] = max(mx[j], dp[i][j]);
    }
  }
  cout << max(mx[0], mx[1]) << '\n';
}

