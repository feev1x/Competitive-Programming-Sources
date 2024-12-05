/**
 *    author:  feev1x
 *    created: 20.11.2024 10:22:04
**/
#include <bits/stdc++.h>

using i64 = long long;

#define double long double

constexpr i64 INF = 1e18;

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double _x, double _y) : x(_x), y(_y) {}
};

int main() {
  int n; scanf("%d", &n);
  std::vector<Point> a(n);
  for (auto &[x1, y1]: a) {
    int x, y; scanf("%d%d", &x, &y);
    x1 = x, y1 = y;
  }
  auto Line = [&](Point p1, Point p2) {
    double A, B, C;
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = -(A * p1.x + B * p1.y);
    return std::tuple{A, B, C};
  };
  auto Dis = [&](double A, double B, double C, Point p) {
    double r = fabs((A*p.x+B*p.y+C) / sqrt(A * A + B * B));
    return r;
  };
  double res = 0;
  for (int i = 0; i < n; ++i) {
    int k = (i + 1) % n;
    for (int j = i + 1; j < n; ++j) {
      int l = (j + 1) % n;
      Point p1(std::abs(a[i].x - a[k].x) / 2., std::abs(a[i].y - a[k].y) / 2.);
      Point p2(std::abs(a[j].x - a[l].x) / 2., std::abs(a[j].y - a[l].y) / 2.);
      auto [A, B, C] = Line(p1, p2);
      double mn = std::min(Dis(A, B, C, a[i]), Dis(A, B, C, a[j]));
      mn = std::min(mn, Dis(A, B, C, a[k]));
      mn = std::min(mn, Dis(A, B, C, a[l]));
      res = std::max(mn, res);
    }
  }
  printf("%.10Lf\n", res);
  return 0;
}
