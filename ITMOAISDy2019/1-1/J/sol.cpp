/**
 *    author:  feev1x
 *    created: 08.11.2024 21:39:37
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  double vp, vf; scanf("%lf%lf", &vp, &vf);
  double a; scanf("%lf", &a);
  double l = 0, r = 1, ans = 0;
  while (r - l >= 1e-5) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    auto Dis = [](double x, double y, double x1, double y1) {
      return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    };
    double ans1 = Dis(0, 1, m1, a) / vp + Dis(m1, a, 1, 0) / vf;
    double ans2 = Dis(0, 1, m2, a) / vp + Dis(m2, a, 1, 0) / vf;
    if (ans1 <= ans2) {
      r = m2 - 1e-5;
      ans = m1;
    } else {
      l = m1 + 1e-5;
      ans = m2;
    }
  }
  printf("%.5lf", ans);
  return 0;
}
