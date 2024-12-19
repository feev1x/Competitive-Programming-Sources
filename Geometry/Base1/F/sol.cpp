/**
 *    author:  feev1x
 *    created: 12.12.2024 15:13:43
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "line1";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

struct Vector {
  int x, y;
  Vector() {};
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%d%d", &x, &y);
    }
  }
  Vector(int _x, int _y) : x(_x), y(_y) {}
  inline Vector operator-(const Vector &a) {
    return Vector(x - a.x, y - a.y);
  }
};

using Point = Vector;

struct Line {
  int A, B, C;
  Line() {}
  Line(Vector v, Point p) {
    A = -v.y;
    B = v.x;
    C = -(A * p.x + B * p.y);
  }
  inline bool check(Point p) {
    return A * p.x + B * p.y + C == 0;
  }
};


int main() {
  Point p1(true), p2(true);
  Line line(Vector(p2 - p1), p1);
  fprintf(OUT, "%d %d %d\n", line.A, line.B, line.C);
  return 0;
}
