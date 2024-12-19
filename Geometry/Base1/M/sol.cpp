/**
 *    author:  feev1x
 *    created: 12.12.2024 17:31:22
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "distance2";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

struct Vector {
  int x, y;
  Vector() {}
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%d%d", &x, &y);
    }
  }
  Vector(int _x, int _y) : x(_x), y(_y) {}
  inline Vector operator-(const Vector &a) {
    return Vector(x - a.x, y - a.y);
  }
  inline Vector norm() {
    return Vector(-y, x);
  }
};

using Point = Vector;

struct Line {
  int A, B, C;
  Line() {}
  Line(Vector v, Point p) {
    A = v.x;
    B = v.y;
    C = -(A * p.x + B * p.y); 
  }
  inline double len() {
    return sqrt(A * A + B * B);
  }
  inline int apply(const Point &p) {
    return A * p.x + B * p.y + C;
  }
  inline double dis(const Point &p) {
    return std::abs(apply(p) / len());
  }
};

int main() {
  Point p(true), p1(true), p2(true);
  Vector v(p2 - p1);
  Line line(v.norm(), p1);
  fprintf(OUT, "%.7lf\n", line.dis(p));
  return 0;
}
