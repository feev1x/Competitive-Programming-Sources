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
  int res = 0;
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    char c; cin >> c;
    if (c == 'L') {
      if (l == -1) {
        l = a;
      }
      res += abs(l - a);
      l = a;
    } else { 
      if (r == -1) {
        r = a;
      }
      res += abs(r - a);
      r = a;
    }
  }
  cout << res << '\n';
}

