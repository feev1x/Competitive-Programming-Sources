/**
 *    author:  feev1x
 *    created: 14.10.2024 19:12:29
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
  int n, k; cin >> n >> k;
  vector<bool> dp(k + 1);
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  for (int s = 0; s <= k; ++s) {
    for (auto u: a) {
      if (s >= u && !dp[s - u]) {
        dp[s] = true;
      }
    }
  }
  if (dp[k]) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }
}
