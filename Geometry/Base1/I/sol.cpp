/**
 *    author:  feev1x
 *    created: 12.12.2024 16:57:38
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "line3";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

struct Vector {
  int x, y;
  Vector() {};
  Vector(int _x, int _y) : x(_x), y(_y) {}
};

using Point = Vector;

struct Line {
  double A, B, C;
  Line() {};
  Line(bool input) {
    if (input) {
      fscanf(IN, "%lf%lf%lf", &A, &B, &C);
    }
  }
  Line(double _A, double _B, double _C) : A(_A), B(_B), C(_C) {}
  inline double apply(const Point &p) {
    return A * p.x + B * p.y + C;
  }
  inline double len() {
    return sqrt(A * A + B * B);
  }
  inline double dis(const Point &p) {
    return apply(p) / len();
  }
  inline double dis(const Line &l) {
    if (l.A == A && l.B == B) {
      return std::abs(l.C - C) / len();
    } else {
      return 0;
    }
  }
  inline double moved(int r) {
    return C + r * len();
  }
};

int main() {
  Line line(true);
  int r; fscanf(IN, "%d", &r);
  fprintf(OUT, "%.7lf %.7lf %.7lf\n", line.A, line.B, line.moved(r));
  fprintf(OUT, "%.7lf %.7lf %.7lf\n", line.A, line.B, line.moved(-r));
  return 0;
}
