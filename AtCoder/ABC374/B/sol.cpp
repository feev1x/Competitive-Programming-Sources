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
  int res = 0;
  for (int i = 0; i < max(s.size(), t.size()); ++i) {
    if (s.size() == i || t.size() == i || s[i] != t[i]) {
      res = i + 1;
      break;
    }
  }
  cout << res << '\n';
}

