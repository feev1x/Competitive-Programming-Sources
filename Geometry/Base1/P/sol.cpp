/**
 *    author:  feev1x
 *    created: 12.12.2024 18:04:52
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "distance3";

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
  inline int operator*(const Vector &a) {
    return x * a.x + y * a.y;
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
    Point p1 = p;
    if ((p1 - st) * dir >= 0) {
      return line.dis(p);
    } 
    return (p1 - st).len();
  }
};

int main() {
  Point p(true), p1(true), p2(true);
  Ray ray(p1, p2 - p1);
  fprintf(OUT, "%.7lf\n", ray.dis(p));
  return 0;
}
