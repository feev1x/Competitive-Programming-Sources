/**
 *    author:  feev1x
 *    created: 12.12.2024 17:25:53
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "distance1";

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
  Line(bool input) {
    if (input) {
      fscanf(IN, "%d%d%d", &A, &B, &C);
    }
  }
  Line(int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
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
  Point p(true);
  Line line(true);
  fprintf(OUT, "%.7lf\n", line.dis(p));
  return 0;
}
