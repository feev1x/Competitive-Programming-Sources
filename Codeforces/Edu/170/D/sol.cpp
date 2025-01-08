/**
 *    author:  feev1x
 *    created: 14.10.2024 21:27:46
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
  int n, m; cin >> n >> m;
  vector<int> r(n), cnt(n);
  vector<int> type, pos;
  vector<vector<int>> dp(m + 1, vector<int>(m + 1));
  vector<int> Iq(m + 1), Pow(m + 1);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    if (r[i] != 0) {
      type.emplace_back(r[i] > 0);
      pos.emplace_back(i);
      if (r[i] > 0) {
        Iq[r[i]]++;
      } else {
        Pow[-r[i]]++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cnt[i] = cnt[i - 1];
    }
    if (r[i] == 0) {
      cnt[i]++;
      for (int iq = 0; iq <= (i ? cnt[i - 1] : 0); ++iq) {
        int power = (i ? cnt[i - 1] : 0) - iq;
        int cnt1 = Pow[power + 1];
        int cnt2 = Iq[iq + 1];
        dp[iq][power + 1] = max(dp[iq][power + 1], dp[iq][power] + cnt1);
        dp[iq + 1][power] = max(dp[iq + 1][power], dp[iq][power] + cnt2);
      }
    } else {
      if (r[i] > 0) {
        Iq[r[i]]--;
      } else {
        Pow[-r[i]]--;
      }
    }
  }
  int res = 0;
  for (int iq = 0; iq <= m; ++iq) {
    int power = m - iq;
    res = max(res, dp[iq][power]);
  }
  cout << res << '\n';
}
