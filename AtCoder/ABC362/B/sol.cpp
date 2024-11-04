/**
 *    author:  feev1x
 *    created: 17.10.2024 08:29:49
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  long double x[3], y[3];
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }
  auto Dis = [](long double x, long double y, long double x1, long double y1) {
    long double dx = x - x1, dy = y - y1;
    return dx * dx + dy * dy;
  };
  long double seg[3];
  for (int i = 0; i < 3; ++i) {
    int j = (i + 1) % 3;
    seg[i] = Dis(x[i], y[i], x[j], y[j]);
  }
  for (int i = 0; i < 3; ++i) {
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;
    debug(seg[i], seg[j], seg[k]);
    if (seg[i] == seg[j] + seg[k]) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
