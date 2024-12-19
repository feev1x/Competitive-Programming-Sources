/**
 *    author:  feev1x
 *    created: 12.12.2024 17:59:30
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "point3";

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
  inline Vector norm() {
    return Vector(-y, x);
  }
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
  inline double len() {
    return sqrt(A * A + B * B);
  }
  inline int apply(const Point &p) {
    return A * p.x + B * p.y + C;
  }
  inline bool contains(const Point &p) {
    return apply(p) == 0;
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
};

struct Segment {
  Point p1, p2;
  Ray r1, r2;
  Segment() {}
  Segment(Point _p1, Point _p2) : p1(_p1), p2(_p2), r1(p1, p2 - p1), r2(p2, p1 - p2) {}
  inline bool contains(const Point &p) {
    return r1.contains(p) && r2.contains(p);
  }
};

int main() {
  Point p(true), p1(true), p2(true);
  Segment seg(p1, p2);
  fprintf(OUT, seg.contains(p) ? "YES\n" : "NO\n");
  return 0;
}
