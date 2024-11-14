/**
 *    author:  feev1x
 *    created: 23.10.2024 16:14:20
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define double long double

class Geometry {
 public:
  struct pt {
    double x, y;
  };
   
  double disSquared(double x, double y, double x1, double y1) {
    return (x - x1) * (x - x1) + (y - y1) * (y - y1);
  }

  double dis(double x, double y, double x1, double y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
  }
   
  double angle(double x1, double y1, double x2, double y2) {
    double crosspr = abs(x1 * y2 - x2 * y1);
    double skalpr = x1 * x2 + y1 * y2;
    return (atan2(crosspr, skalpr) / acos(-1)) * 180;
  }
   
  double disfromdottolnSquared(double x, double y, double x1, double y1, double x2, double y2) {
    double A = y1 - y2;
    double B = x2 - x1;
    double C = -(A * x1 + B * y1);
    return (A * x + B * y + C) * (A * x + B * y + C) / (A * A + B * B);
  }
   
  double disfromdottosegSquared(double x, double y, double x1, double y1, double x2, double y2) {
    if (angle(x - x1, y - y1, x2 - x1, y2 - y1) >= 90) return disSquared(x, y, x1, y1);
    if (angle(x - x2, y - y2, x1 - x2, y1 - y2) >= 90) return disSquared(x, y, x2, y2);
    return disfromdottolnSquared(x, y, x1, y1, x2, y2);
  }
   
  tuple<double, double, double> equation(double x1, double y1, double x2, double y2) {
    double A = y1 - y2;
    double B = x2 - x1;
    double C = -(A * x1 + B * y1);
    return {A, B, C};
  }
   
  bool onseg(double x, double y, double x1, double y1, double x2, double y2) {
    if (min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2)) {
      return fabs((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1)) < 1e-9;
    }
    return false;
  }
   
   
  pt intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    auto [A1, B1, C1] = equation(x1, y1, x2, y2);
    auto [A2, B2, C2] = equation(x3, y3, x4, y4);
    double y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
    double x = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1);
    return {x, y};
  }
   
  double disfromsegtoseg(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    auto [x, y] = intersection(x1, y1, x2, y2, x3, y3, x4, y4);
    if (onseg(x, y, x1, y1, x2, y2) && onseg(x, y, x3, y3, x4, y4)) {
      return 0.; 
    }
    double mn = disfromdottosegSquared(x3, y3, x1, y1, x2, y2);
    mn = min(mn, disfromdottosegSquared(x4, y4, x1, y1, x2, y2));
    mn = min(mn, disfromdottosegSquared(x1, y1, x3, y3, x4, y4));
    mn = min(mn, disfromdottosegSquared(x2, y2, x3, y3, x4, y4));
    return sqrt(mn);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);  
  int m; cin >> m;
  vector<double> xa(m + 1), ya(m + 1), xb(m + 1), yb(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
  }
  int cnt = 0;
  Geometry geo;
  auto Check = [&](int i, int j, int k) {
    if (geo.disfromsegtoseg(xa[i], ya[i], xb[i], yb[i], xa[j], ya[j], xb[j], yb[j]) <=
        geo.dis(xa[k], ya[k], xb[k], yb[k])) {
      return true;
    }
    if (geo.disfromsegtoseg(xa[i], ya[i], xb[i], yb[i], xa[k], ya[k], xb[k], yb[k]) <=
        geo.dis(xa[j], ya[j], xb[j], yb[j])) {
      return true;
    }
    if (geo.disfromsegtoseg(xa[k], ya[k], xb[k], yb[k], xa[j], ya[j], xb[j], yb[j]) <=
        geo.dis(xa[i], ya[i], xb[i], yb[i])) {
      return true;
    }
    return false;
  };
  for (int i = 1; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      for (int k = j + 1; k <= m; ++k) {
        if (Check(i, j, k)) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
