/**
 *    author:  feev1x
 *    created: 12.12.2024 19:09:17
**/
#include <bits/stdc++.h>

using i64 = long long;

#define int i64

const std::string FL = "raydist";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

enum Type {
  POINT,
  INF,
  NONE
};

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
      fscanf(IN, "%lld%lld%lld", &A, &B, &C);
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
    Vector v1(-C, B), v2(-l.C, l.B);
    double delta = norm() % l.norm();
    if (delta == 0) {
      return Point(1e9, 1e9);
    }
    double delta_x = v1 % v2;
    v1 = Vector(A, -C);
    v2 = Vector(l.A, -l.C);
    double delta_y = v1 % v2;
    return Point(delta_x / delta, delta_y / delta);
  }
};

struct Ray {
  Line line;
  Point st;
  Vector dir;
  Ray() {}
  Ray(Point _st, Vector _dir) : line(_dir.norm(), _st), st(_st), dir(_dir) {}
  inline bool contains(const Point &p) {
    Point p1 = p;
    return line.contains(p) && (p1 - st) * dir >= 0;
  }
  inline double dis(const Point &p) {
    if (contains(p)) {
      return 0;
    }
    Point p1 = p;
    if ((p1 - st) * dir >= 0) {
      return line.dis(p);
    } 
    return (p1 - st).len();
  }
  inline double dis(Ray &r) {
    Point p(line.intersection(r.line));
    if (contains(p) && r.contains(p)) {
      return 0;
    }
    return std::min(dis(r.st), r.dis(st));
  }
};

signed main() {
  Point st1(true), p1(true), st2(true), p2(true);
  Ray r1(st1, p1 - st1), r2(st2, p2 - st2);
  fprintf(OUT, "%.10lf\n", r1.dis(r2));
  return 0;
}

