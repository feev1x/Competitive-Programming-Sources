/**
 *    author:  feev1x
 *    created: 12.12.2024 14:13:21
**/
#include <bits/stdc++.h>

using i64 = long long;

FILE *IN = std::fopen("area1.in", "r");
FILE *OUT = std::fopen("area1.out", "w");

struct Vector {
  int x, y;
  Vector() {}
  Vector(int _x, int _y) : x(_x), y(_y) {}
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%d%d", &x, &y);
    }
  }
  inline Vector operator+(const Vector &a) {
    return Vector(x + a.x, y + a.y);
  }
  inline Vector operator-(const Vector &a) {
    return Vector(x - a.x, y - a.y);
  }
  inline int operator%(const Vector &a) {
    return x * a.y - y * a.x;
  }
};

using Point = Vector;

int main() {
  std::array<Vector, 3> p;
  for (auto &[x, y]: p) {
    fscanf(IN, "%d%d", &x, &y);
  }
  Vector a = p[2] - p[0], b = p[1] - p[0];
  double area = std::abs(a % b) / 2.0;
  fprintf(OUT, "%.7lf\n", area);
  return 0;
}
