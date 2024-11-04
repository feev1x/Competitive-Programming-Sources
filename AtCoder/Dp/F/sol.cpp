/**
 *    author:  feev1x
 *    created: 14.10.2024 14:04:34
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 2, vector<int>(m + 2));
  s = " " + s;
  t = " " + t;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = n, j = m;
  string res;
  while (dp[i][j]) {
    if (dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i][j - 1]) {
      res += s[i];
      i--, j--;
    } else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
}
