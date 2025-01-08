/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int y; cin >> y;
  if (y % 4 != 0) {
    cout << 365 << '\n';
  } else if (y % 100 != 0) {
    cout << 366 << '\n';
  } else if (y % 400 != 0) {
    cout << 365 << '\n';
  } else {
    cout << 366 << '\n';
  }
}

