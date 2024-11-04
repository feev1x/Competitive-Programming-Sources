/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i + 2 < n; ++i) {
    if (s.substr(i, 3) == "ABC") {
      cnt++;
    }
  }
  while (q--) {
    int x; cin >> x;
    char c; cin >> c;
    x--;
    if (s[x] == c) {
      cout << cnt << '\n';
    } else {
      for (int i = x - 2; i <= x; ++i) {
        if (i >= 0 && i + 2 < n) {
          if (s.substr(i, 3) == "ABC") {
            cnt--;
          }
        }
      }
      s[x] = c;
      for (int i = x - 2; i <= x; ++i) {
        if (i >= 0 && i + 2 < n) {
          if (s.substr(i, 3) == "ABC") {
            cnt++;
          }
        }
      }
      cout << cnt << '\n';
    }
  }
}

