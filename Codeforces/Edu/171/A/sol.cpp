/**
 *    author:  feev1x
 *    created: 28.10.2024 20:35:14
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
  int tt; cin >> tt;
  while (tt--) {
    int X, Y, K; cin >> X >> Y >> K;
    int ax, ay, bx, by, cx, cy, dx, dy;
    ax = 0;
    ay = 0;
    bx = min(X, Y);
    by = min(X, Y);
    cx = 0;
    cy = min(X, Y);
    dx = min(X, Y);
    dy = 0;
    cout << ax << ' ' << ay << ' ' << bx << ' ' << by << '\n';
    cout << cx << ' ' << cy << ' ' << dx << ' ' << dy << '\n';
  }
  return 0;
}
