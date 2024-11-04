/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    int cnt = n + 1;
    for (int i = 0; i < k; ++i) {
      int r, c; cin >> r >> c;
      cnt -= (1 + (r != c));
    }
    vector<int64_t> dp(cnt);
    while (--cnt) {
      if (!dp[cnt]) dp[cnt] = 1;
      dp[cnt - 1] = (dp[cnt - 1] + dp[cnt]) % mod;
      if (cnt - 2 >= 0) {
        dp[cnt - 2] = (2 * (dp[cnt - 2] + (cnt - 1) * dp[cnt])) % mod;
      }
    }
    cout << max(dp[0], int64_t(1)) << '\n';
  }
}

