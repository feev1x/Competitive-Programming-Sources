/**
 *    author:  feev1x
 *    created: 12.12.2024 16:06:06
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "bisector";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

constexpr double pi = acos(-1);

struct Vector {
  double x, y;
  Vector() {};
  Vector(bool input) {
    if (input) {
      fscanf(IN, "%lf%lf", &x, &y);
    }
  }
  Vector(double _x, double _y) : x(_x), y(_y) {}
  inline Vector operator-(const Vector &a) {
    return Vector(x - a.x, y - a.y);
  }
  inline Vector operator+(const Vector &a) {
    return Vector(x + a.x, y + a.y);
  }
  inline double operator*(const Vector &a) {
    return x * a.x + y * a.y;
  }
  inline double operator%(const Vector &a) {
    return x * a.y - y * a.x;
  }
  inline double angle() {
    return atan2(y, x);
  }
  inline double angle(const Vector &a) {
    return atan2(*this % a, *this * a);
  }
  inline void rotate(double deg) {
    double r = sqrt(x * x + y * y), alpha = angle();
    alpha = alpha + deg;
    if (alpha < 0) {
      alpha += 2 * pi;
    } else if (alpha >= 2 * pi) {
      alpha -= 2 * pi;
    }
    x = r * cos(alpha);
    y = r * sin(alpha);
  }
  inline Vector norm() {
    return Vector(-y, x);
  }
};

using Point = Vector;

struct Line {
  double A, B, C;
  Line() {};
  Line(Vector v, Point p) {
    A = v.x;
    B = v.y;
    C = -(A * p.x + B * p.y);
  }
};

int main() {
  Point p1(true), p2(true), p3(true);
  Vector v1(p2 - p1), v2(p3 - p1);
  if (v1 % v2 > 0) {
    std::swap(v1, v2);
  }
  v1.rotate(v1.angle(v2) / 2.);
  Line line(v1.norm(), p1);
  fprintf(OUT, "%.7lf %.7lf %.7lf\n", line.A, line.B, line.C);
  return 0;
}
