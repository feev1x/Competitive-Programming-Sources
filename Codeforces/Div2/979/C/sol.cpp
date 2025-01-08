/**
 *    author:  feev1x
 *    created: 19.10.2024 20:11:04
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = s.front() == '1' || s.back() == '1';
    for (int i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == '1' && s[i + 1] == '1') {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
