/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<string> st;
  string s; cin >> s;
  for (int sz = 1; sz <= s.size(); ++sz) {
    for (int i = 0; i + sz - 1 < s.size(); ++i) {
      st.emplace(s.substr(i, sz));
    }
  }
  cout << st.size() << '\n';
}

