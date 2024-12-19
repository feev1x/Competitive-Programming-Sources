/**
 *    author:  feev1x
 *    created: 12.12.2024 16:00:20
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "line2";

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
};

int main() {
  Point p(true);
  Vector v(true);
  Line line(v, p);
  fprintf(OUT, "%d %d %d\n", line.A, line.B, line.C);
  return 0;
}
