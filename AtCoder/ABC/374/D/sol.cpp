/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

double dis(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; double s, t; cin >> n >> s >> t;
  vector<double> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 0);
  double res = 1e18;
  do {
    for (int mask = 0; mask < (1 << n); ++mask) {
      double x = 0, y = 0;
      double ans = 0;
      for (auto nw: vec) {
        double dist;
        if (mask & (1 << nw)) {
          dist = dis(x, y, a[nw], b[nw]);
          x = c[nw], y = d[nw];
        } else {
          dist = dis(x, y, c[nw], d[nw]);
          x = a[nw], y = b[nw];
        }
        ans += dist / s;
        dist = dis(a[nw], b[nw], c[nw], d[nw]);
        ans += dist / t;
      }
      res = min(res, ans);
    }
  } while (next_permutation(vec.begin(), vec.end()));
  cout << fixed << setprecision(8) << res << '\n';
}

