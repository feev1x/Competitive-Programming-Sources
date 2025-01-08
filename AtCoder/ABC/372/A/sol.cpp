/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  string ans;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '.') ans += s[i];
  }
  cout << ans << '\n';
}

