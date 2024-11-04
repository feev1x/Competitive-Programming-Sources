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
  int64_t res = 0;
  int nw = 0;
  for (int i = 0; i < 26; ++i) {
    if (s[i] == 'A') nw = i;
  }
  for (int i = 1; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (s[j] == 'A' + i) {
        res += abs(nw - j);
        nw = j;
      }
    }
  }
  cout << res << '\n';
}

