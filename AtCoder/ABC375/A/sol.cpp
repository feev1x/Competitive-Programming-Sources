/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < n - 2; ++i) {
    if (s[i] == '#' && s[i + 2] == '#' && s[i + 1] == '.') {
      cnt++;
    }
  }
  cout << cnt << '\n';
}

