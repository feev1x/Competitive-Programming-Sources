/**
 *    author:  feev1x
 *    created: 12.12.2024 13:50:44
**/
#include <bits/stdc++.h>

using i64 = long long;

FILE *IN = std::fopen("angle1.in", "r");
FILE *OUT = std::fopen("angle1.out", "w");

constexpr double pi = acos(-1);

struct Vector {
  int x, y;
  Vector() {}
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%d%d", &x, &y);
    }
  }
  inline double angle() {
    return atan2(y, x);
  }
};

int main() {
  Vector v(true);
  double ang = v.angle();
  if (ang < 0) {
    ang += 2 * pi;
  }
  fprintf(OUT, "%.7lf\n", ang);
  return 0;
}
