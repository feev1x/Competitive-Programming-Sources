/**
 *    author:  feev1x
 *    created: 12.12.2024 13:39:10
**/
#include <bits/stdc++.h>

using i64 = long long;

FILE *IN = std::fopen("length.in", "r");
FILE *OUT = std::fopen("length.out", "w");

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  inline void read() {
    fscanf(IN, "%d%d", &x, &y);
  }
};

struct Vector {
  int x, y;
  Vector() : x(0), y(0) {}
  Vector(Point p1, Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}
  inline double size() {
    return sqrt(x * x + y * y);
  }
};

int main() {
  Point p1, p2; p1.read(), p2.read();
  Vector v(p1, p2);
  fprintf(OUT, "%.7lf\n", v.size());
  return 0;
}
