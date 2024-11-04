/**
 *    author:  feev1x
 *    created: 15.10.2024 09:13:24
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  vector<vector<pair<int64_t, int64_t>>> dp(n + 2, vector<pair<int64_t, int64_t>>(n + 2));
  a.insert(a.begin(), 0);
  for (int l = n; l >= 1; --l) {
    for (int r = l; r <= n; ++r) {
      int sz = n - (r - l + 1);
      if (sz % 2 == 0) {
        if ((a[l] + dp[l + 1][r].first) - dp[l + 1][r].second > (a[r] + dp[l][r - 1].first) - dp[l][r - 1].second) {
          dp[l][r] = {a[l] + dp[l + 1][r].first, dp[l + 1][r].second};
        } else {
          dp[l][r] = {a[r] + dp[l][r - 1].first, dp[l][r - 1].second};
        }
      } else {
        if (dp[l + 1][r].first - (a[l] + dp[l + 1][r].second) < dp[l][r - 1].first - (dp[l][r - 1].second + a[r])) {
          dp[l][r] = {dp[l + 1][r].first, a[l] + dp[l + 1][r].second};
        } else {
          dp[l][r] = {dp[l][r - 1].first, a[r] + dp[l][r - 1].second};
        }
      }
    }
  }
  cout << dp[1][n].first - dp[1][n].second << '\n';
}
