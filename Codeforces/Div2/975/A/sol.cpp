/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> dp(n);
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      cin >> dp[i];
      if (i & 1) sum1 = max(sum1, dp[i]), cnt1++;
      else sum2 = max(sum2, dp[i]), cnt2++;
    }
    cout << max(sum1 + cnt1, sum2 + cnt2) << '\n';
  }
}

