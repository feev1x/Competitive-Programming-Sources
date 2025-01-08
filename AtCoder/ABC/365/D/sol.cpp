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
  vector<vector<int>> dp(3, vector<int>(n + 1, -1));
  string s1; cin >> s1;
  s1 = " " + s1;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (s1[i] == 'R') {
      s[i] = 0;
    } else if (s1[i] == 'P') {
      s[i] = 1;
    } else {
      s[i] = 2;
    }
  }
  dp[0][0] = dp[1][0] = dp[2][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (dp[j][i - 1] != -1) {
        if (j != (s[i] + 1) % 3) {
          dp[(s[i] + 1) % 3][i] = max(dp[(s[i] + 1) % 3][i], dp[j][i - 1] + 1);
          if (j != s[i])
          dp[s[i]][i] = max(dp[s[i]][i], dp[j][i - 1]);
        } else {
          dp[s[i]][i] = max(dp[s[i]][i], dp[j][i - 1]);
        }
      }
    }
  }
  cout << max({dp[0][n], dp[1][n], dp[2][n]}) << '\n';
}

