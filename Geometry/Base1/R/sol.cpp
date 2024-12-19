/**
 *    author:  feev1x
 *    created: 12.12.2024 18:37:17
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "intersec1";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

struct Vector {
  double x, y;
  Vector() {}
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%lf%lf", &x, &y);
    }
  }
  Vector(double _x, double _y) : x(_x), y(_y) {}
  inline Vector operator-(const Vector &a) {
    return Vector(x - a.x, y - a.y);
  }
  inline double operator*(const Vector &a) {
    return x * a.x + y * a.y;
  }
  inline double operator%(const Vector a) {
    return x * a.y - y * a.x;
  }
  inline double dis(const Vector &a) {
    return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
  }
  inline Vector norm() {
    return Vector(-y, x);
  }
  inline double len() {
    return sqrt(x * x + y * y);
  }
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
  Line(Vector v, Point p) {
    A = v.x;
    B = v.y;
    C = -(A * p.x + B * p.y);
  } 
  Line(int _A, int _B, int _C) : A(_A), B(_B), C(_C) {}
  inline double len() {
    return sqrt(A * A + B * B);
  }
  inline int apply(const Point &p) {
    return A * p.x + B * p.y + C;
  }
  inline bool contains(const Point &p) {
    return apply(p) == 0;
  }
  inline double dis(const Point &p) {
    return std::abs(apply(p) / len());
  }
  inline Vector norm() {
    return Vector(A, B);
  }
  inline Point intersection(Line &l) {
    if (l.A == A && l.B == B) {
      if (l.C == C) {
        return -2;
      } else {
        return -1;
      }
    }
    Vector v1(-C, B), v2(-l.C, l.B);
    double delta = norm() % l.norm();
    if (delta == 0) {
      return -2;
    }
    double delta_x = v1 % v2;
    v1 = Vector(A, -C);
    v2 = Vector(l.A, -l.C);
    double delta_y = v1 % v2;
    return Point(delta_x / delta, delta_y / delta);
  }
};

int main() {
  Line line1(true), line2(true);  
  Point p(line1.intersection(line2));
  fprintf(OUT, "%lf %lf\n", p.x, p.y);
  return 0;
}
