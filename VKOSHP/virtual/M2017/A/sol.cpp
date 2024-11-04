/**
 *    author:  feev1x
 *    created: 21.10.2024 09:04:13
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double w, h, y1, y2; cin >> w >> h >> y1 >> y2;
  double d1 = h - y1;
  double d2 = h - y2;
  bool flag = true;
  for (int i = 1; i <= w; ++i) {
    if (d1 >= i) {
      if (d2 > w - i) {
        flag = false;
      }
    }
  }
  d1 = y1;
  d2 = y2;
  for (int i = 1; i <= w; ++i) {
    if (d1 >= i) {
      if (d2 > w - i) {
        flag = false;
      }
    }
  }
  if (flag) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
