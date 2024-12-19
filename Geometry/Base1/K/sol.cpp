/**
 *    author:  feev1x
 *    created: 12.12.2024 17:17:01
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "position";

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
};

using Point = Vector;

struct Line {
  int A, B, C;
  Line() {};
  Line(bool input) {
    if (input) {
      fscanf(IN, "%d%d%d", &A, &B, &C);
    }
  }
  Line(int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
  inline int apply(const Point &p) {
    return A * p.x + B * p.y + C;
  }
};

int main() {
  Point p1(true), p2(true);
  Line line(true);
  fprintf(OUT, (line.apply(p1) < 0) == (line.apply(p2) < 0) ? "YES\n" : "NO\n");
  return 0;
}
