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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    if (s == t) {
      cout << 0 << '\n';
      continue;
    }
    if (s[0] != t[0]) {
      cout << -1 << '\n';
      continue;
    }
    int res = 2;
    if (s.size() > t.size()) swap(s, t), swap(n, m);
    int cntp = 0, cnts = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) cntp++;
      else break;
    }
    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; --i, --j) {
      if (s[j] == t[i]) cnts++;
      else break;
    }
    if (cntp + cnts >= n) {
      res = 1;
    }
    cout << res << '\n';
  }
}

