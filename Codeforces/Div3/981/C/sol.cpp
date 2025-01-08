/**
 *    author:  feev1x
 *    created: 25.10.2024 08:12:28
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n + 2);
    vector dp(n + 2, vector<int>(2));
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cnt += (a[i] == a[i - 1]);
    }
    for (int i = 1; i <= (n + 1) / 2; ++i) {
      dp[i]
    }
    cout << cnt << '\n';
  }
  return 0;
}
