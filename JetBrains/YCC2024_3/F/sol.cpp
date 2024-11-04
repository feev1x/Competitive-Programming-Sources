/**
 *    author:  feev1x
 *    created: 29.10.2024 14:41:41
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
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> dp;
  dp.emplace(0);
  for (auto u: a) {
    set<int> ndp;
    for (auto sm: dp) {
      ndp.emplace((sm + u) % m);
    }
    if (ndp.find(0) != ndp.end()) {
      cout << "YES\n";
      return 0;
    }
    dp.insert(ndp.begin(), ndp.end());
  }
  cout << "NO\n";
  return 0;
}
