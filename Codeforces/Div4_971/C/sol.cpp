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
    int x, y, k; cin >> x >> y >> k;
    x = (x / k) + (x % k > 0);
    y = (y / k) + (y % k > 0);
    if (y > x) x = y;
    if (x > y) y = x - 1;
    cout << x + y << '\n';
  }
}

