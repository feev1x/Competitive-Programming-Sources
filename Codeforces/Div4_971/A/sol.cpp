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
    int a, b; cin >> a >> b;
    int res = 1000;
    for (int i = a; i <= b; ++i) res = min(res, (i - a) + (b - i));
    cout << res << '\n';
  }
}

