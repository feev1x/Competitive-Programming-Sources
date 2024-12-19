/**
 *    author:  feev1x
 *    created: 12.12.2024 13:57:46
**/
#include <bits/stdc++.h>

using i64 = long long;

FILE *IN = std::fopen("angle2.in", "r");
FILE *OUT = std::fopen("angle2.out", "w");

struct Vector {
  int x, y;
  Vector() {}
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%d%d", &x, &y);
    }
  }
  inline int operator%(const Vector &a) {
    return x * a.y - y * a.x;
  }
  inline int operator*(const Vector &a) {
    return x * a.x + y * a.y;
  }
  inline double angle() {
    return atan2(y, x);
  }
  inline double angle(const Vector &a) {
    return std::abs(atan2(*this % a, *this * a));
  }
};

int main() {
  Vector v1(true), v2(true);
  fprintf(OUT, "%.7lf\n", v1.angle(v2));
  return 0;
}
