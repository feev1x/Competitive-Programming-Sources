/**
 *    author:  feev1x
 *    created: 12.12.2024 15:05:50
**/
#include <bits/stdc++.h>

using i64 = long long;

FILE *IN = std::fopen("area.in", "r");
FILE *OUT = std::fopen("area.out", "w");

struct Vector {
  int x, y;
  Vector() {}
  Vector(int _x, int _y) : x(_x), y(_y) {}
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
  int n; fscanf(IN, "%d", &n);
  std::vector<Point> p(n);
  for (auto &[x, y]: p) {
    fscanf(IN, "%d%d", &x, &y);
  }
  int sum = 0;
  for (int i = 2; i < n; ++i) {
    Vector a = p[i] - p[0];
    Vector b = p[i - 1] - p[0];
    sum += a % b;
  }
  double area = std::abs(sum) / 2.0;
  fprintf(OUT, "%.7lf\n", area);
  return 0;
}
