/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
const double pi = acos(-1);

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double n; cin >> n;
  double x1, y1, xn2, yn2; cin >> x1 >> y1 >> xn2 >> yn2;
  double cx = (x1 + xn2) / 2., cy = (y1 + yn2) / 2.;
  double d = 2 * pi / n;
  double x2 = cx + (x1 - cx) * cos(d) - (y1 - cy) * sin(d);
  double y2 = cy + (x1 - cx) * sin(d) + (y1 - cy) * cos(d);
  cout << fixed << setprecision(12) << x2 << ' ' << y2 << '\n';
}

