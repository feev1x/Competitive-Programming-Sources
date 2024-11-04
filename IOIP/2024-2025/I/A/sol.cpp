/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  s = " " + s;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int x = s[i] - '0';
    if (x) {
      x = ((n - 1) & (i - 1)) == (i - 1);
    }
    res ^= x;
  }
  cout << res << '\n';
}
