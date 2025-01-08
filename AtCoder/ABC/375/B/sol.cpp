/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

double dis(double x, double y, double x1, double y1) {
  return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  double res = 0;
  double x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    double X, Y; cin >> X >> Y;
    res += dis(x, y, X, Y);
    x = X, y = Y;
  }
  res += dis(x, y, 0, 0);
  cout << fixed << setprecision(7) << res << '\n';
}

