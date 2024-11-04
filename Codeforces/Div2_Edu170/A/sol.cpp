/**
 *    author:  feev1x
 *    created: 14.10.2024 20:27:53
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
  int tt; cin >> tt;
  while (tt--) {
    string s, t; cin >> s >> t;
    int cnt = 0;
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
      if (s[i] == t[i]) {
        cnt++;
      } else {
        break;
      }
    }
    int n = s.size(), m = t.size();
    cout << (m - cnt) + (n - cnt) + cnt + (cnt > 0) << '\n';
  }
}
