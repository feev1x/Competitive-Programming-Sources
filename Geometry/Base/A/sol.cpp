/**
 *    author:  feev1x
 *    created: 17.11.2024 10:41:25
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr double pi = acos(-1);

struct Vector {
  int x, y, sqr;
  double alpha, r;
  Vector(int _x, int _y) : x(_x), y(_y) {
    alpha = atan2(y, x); 
    if (alpha < 0) {
      alpha += pi * 2;
    }
    r = sqrt(x * x + y * y);
    sqr = x * x + y * y;
  }
  double angle() {
    return alpha;
  }
  int cross(constexpr Vector &b) {
    return x * b.y - y * b.x;
  }
  int dot(constexpr Vector &b) {
    return x * b.x + y * b.y;
  }
};

int main() {
  std::freopen("angle1.in", "r", stdin);
  std::freopen("angle1.out", "w", stdout);
  int x, y; scanf("%d%d", &x, &y);
  Vector v(x, y);
  printf("%.9lf\n", v.angle());
  return 0;
}
