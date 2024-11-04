/**
 *    author:  feev1x
 *    created: 15.10.2024 11:58:58
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
//  freopen("traffic.in", "r", stdin);
//  freopen("traffic.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<vector<int64_t>> nerv(301, vector<int64_t>(100001));
  for (int64_t i = 1; i <= 1e5; ++i) {
    for (int64_t k = 1; k <= min(i, int64_t(300)); ++k) {
      int j = i - k;
      nerv[k][i] = j * (j - 1) / 2 + nerv[k][i - k];
    }
  }
  for (int i = 1; i <= 1e5; ++i) {
    nerv[0][i] = 1e18;
  }
  int n; int64_t k; cin >> n >> k;
  vector<int64_t> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  vector<vector<pair<int64_t, int>>> dp(n + 1, vector<pair<int64_t, int>>(k + 1, {1e18, 0}));
  dp[0][0].first = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int us = 1; us + j <= k; ++us) {
        if (dp[i][j + us].first > dp[i - 1][j].first + nerv[us][c[i]]) {
          dp[i][j + us].first = dp[i - 1][j].first + nerv[us][c[i]];
          dp[i][j + us].second = us;
        }
      }
    }
  }
  cout << dp[n][k].first << '\n';
  vector<int> K(n + 1);
  int j = k;
  for (int i = n; i >= 1; --i) {
    K[i] = dp[i][j].second;
    j -= dp[i][j].second;
  }
  for (int i = 1; i <= n; ++i) {
    cout << K[i] << " \n"[i == n];
  }
}
