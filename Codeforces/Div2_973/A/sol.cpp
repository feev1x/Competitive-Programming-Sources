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
    int n, x, y; cin >> n >> x >> y;
    int cnt = n / y + (n % y > 0);
    if (x >= y) {
      cout << cnt << '\n';
    } else {
      cout << n / x + (n % x > 0) << '\n';
    }
  }
}

