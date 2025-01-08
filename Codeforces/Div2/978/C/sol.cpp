/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

bool c(string s) {
  int cnt = count(s.begin(), s.end(), 'A');
  return cnt >= 2;
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; ++i) {
      cin >> s[i];
    }
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(4, vector<int>(n)));
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n) {
        string str;
        str += s[1][i];
        str += s[0][i];
        str += s[0][i + 1];
        dp[0][1][i + 1] = max(dp[0][1][i + 1], (i == 0 ? 0: dp[0][0][i - 1]) + c(str));
        str.clear();
        str += s[0][i];
        str += s[1][i];
        str += s[1][i + 1];
        dp[1][1][i + 1] = max(dp[1][1][i + 1], (i == 0 ? 0: dp[0][0][i - 1]) + c(str));
        str.clear();
        str += s[1][i];
        str += s[1][i + 1];
        str += s[0][i + 1];
        dp[0][0][i + 1] = max(dp[0][0][i + 1], dp[0][1][i] + c(str));
        str.clear();
        str += s[0][i];
        str += s[0][i + 1];
        str += s[1][i + 1];
        dp[0][0][i + 1] = max(dp[0][0][i + 1], dp[1][1][i] + c(str));
        if (i + 2 < n) {
          str.clear();
          str += s[1][i];
          str += s[1][i + 1];
          str += s[1][i + 2];
          int cs = c(str);
          dp[0][0][i + 2] = max(dp[0][0][i + 2], dp[0][3][i + 2] + cs);
          dp[1][1][i + 2] = max(dp[1][1][i + 2], dp[0][2][i + 1] + cs);
          dp[1][2][i + 2] = max(dp[1][2][i + 2], dp[0][1][i] + cs);
          dp[1][3][i + 2] = max(dp[1][3][i + 2], (i == 0 ? 0: dp[0][0][i - 1]) + cs);

          str.clear();
          str += s[0][i];
          str += s[0][i + 1];
          str += s[0][i + 2];
          cs = c(str);

          dp[0][0][i + 2] = max(dp[0][0][i + 2], dp[1][3][i + 2] + cs);
          dp[0][1][i + 2] = max(dp[0][1][i + 2], dp[1][2][i + 1] + cs);
          dp[0][2][i + 2] = max(dp[0][2][i + 2], dp[1][1][i] + cs);
          dp[0][3][i + 2] = max(dp[0][3][i + 2], (i == 0 ? 0: dp[0][0][i - 1]) + cs);
        }
      }
    }
    cout << dp[0][0][n - 1] << '\n';
  }
}

