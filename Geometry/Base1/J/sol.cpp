/**
 *    author:  feev1x
 *    created: 12.12.2024 17:10:31
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "point1";

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
  Line() {};
  Line(bool input) {
    if (input) {
      fscanf(IN, "%d%d%d", &A, &B, &C);
    }
  }
  Line (int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
  inline bool check(const Point &p) {
    return A * p.x + B * p.y + C == 0;
  }
};

int main() {
  Point p(true);
  Line line(true);
  fprintf(OUT, line.check(p) ? "YES\n" : "NO\n");
  return 0;
}
