/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t; cin >> s >> t;
  int n = s.size();
  vector<string> ans;
  vector<int> a(s.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] > t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] < t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  }
  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x << '\n';
  }
}

