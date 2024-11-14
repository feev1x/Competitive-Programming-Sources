/**
 *    author:  feev1x
 *    created: 24.10.2024 12:09:12
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
  int n; cin >> n;
  map<vector<bool>, map<string, vector<int>>> mp;
  for (int i = 1; i <= n; ++i) {
    string s, t; cin >> s >> t;
    vector<bool> chk(26);
    for (int j = 0; j < t.size(); ++j) {
      chk[t[j] - 'a'] = true;
    }
    while (!s.empty() && chk[s.back() - 'a']) {
      s.pop_back();
    }
    debug(s, chk);
    mp[chk][s].emplace_back(i);
  }
  vector<vector<int>> ans;
  for (auto [key, val]: mp) {
    for (auto [key1, val1]: val) {
      vector<int> sm;
      for (auto u: val1) {
        sm.emplace_back(u);
      }
      ans.emplace_back(sm);
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].size() << ' ';
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
