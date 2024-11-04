/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  vector<vector<pair<int64_t, char>>> dp(2, vector<pair<int64_t, char>>(n + 1));
  dp[0][0] = make_pair(a[0], '1');
  dp[1][0] = make_pair(a[0] * 2, '1');
  for (int i = 1; i < n; ++i) {
    dp[1][i] = make_pair(dp[0][i - 1].first + a[i] * 2, 'O');
    if (dp[1][i - 1].first > dp[0][i - 1].first) {
      dp[0][i] = make_pair(dp[1][i - 1].first + a[i], 'M');
    } else {
      dp[0][i] = make_pair(dp[0][i - 1].first + a[i], 'O');
    }
  }
  string s;
  if (dp[1][n - 1].first > dp[0][n - 1].first) {
    cout << dp[1][n - 1].first << '\n';
    s += "M";
  } else {
    cout << dp[0][n - 1].first << '\n';
    s += "O";
  }
  for (int i = n - 1; i > 0; --i) {
    if (s.back() == 'M') {
      s += dp[1][i].second;
    } else {
      s += dp[0][i].second;
    }
  }
  reverse(s.begin(), s.end());
  cout << s << '\n';
}

