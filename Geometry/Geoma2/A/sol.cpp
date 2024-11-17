/**
 *    author:  feev1x
 *    created: 17.11.2024 11:16:35
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Point {
  i64 x, y;
  Point() : x(0), y(0) {}
  Point(i64 _x, i64 _y) : x(_x), y(_y) {}
  inline long double dis(const Point &a) {
    return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
  }
  inline i64 sqdis(const Point &a) {
    return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y);
  }
  inline bool operator>(const Point &a) {
    if (a.x == x) {
      return y > a.y;
    }
    return x > a.x;
  }
  inline bool operator<(const Point &a) {
    if (a.x == x) {
      return y < a.y;
    }
    return x < a.x;
  }
  inline bool operator>=(const Point &a) {
    if (a.x == x) {
      return y >= a.y;
    }
    return x > a.x;
  }
  inline bool operator<=(const Point &a) {
    if (a.x == x) {
      return y <= a.y;
    }
    return x < a.x;
  }
  inline bool operator==(const Point &a) {
    return x == a.x && y == a.y;
  }
};

struct Vector {
  i64 x, y;
  Vector() : x(0), y(0) {}
  Vector(i64 _x, i64 _y) : x(_x), y(_y) {}
  Vector(i64 x1, i64 y1, i64 x2, i64 y2) {
    x = x2 - x1;
    y = y2 - y1;
  }
  Vector(const Point &p1, const Point &p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
  }
  inline i64 cross(const Vector &a) {
    return x * a.y - y * a.x;
  }
  inline i64 dot(const Vector &a) {
    return x * a.x + y * a.y;
  }
  inline long double size() {
    return sqrt(x * x + y * y);
  }
  inline i64 sqsize() {
    return x * x + y * y;
  }
};

int main() {
  int n; scanf("%d", &n);
  std::vector<Point> a(n);
  for (auto &pt: a) {
    scanf("%lld%lld", &pt.x, &pt.y);
  }
  std::sort(a.begin(), a.end());
  std::vector<Point> up, down;
  up.emplace_back(a.front());
  down.emplace_back(a.front());
  Point start = a.front(), end = a.back();
  auto Up = [&](Point pt, Point l, Point r) {
    Vector v1(r, l), v2(r, pt);
    return v1.cross(v2) > 0;
  };
  auto Down = [&](Point pt, Point l, Point r) {
    Vector v1(r, l), v2(r, pt);
    return v1.cross(v2) < 0;
  };
  for (int i = 1; i < n; ++i) {
    if (i == n - 1 || Up(a[i], start, end)) {
      while (up.size() >= 2 && !Up(up.back(), up[up.size() - 2], a[i])) {
        up.pop_back();
      }
      up.emplace_back(a[i]);
    }
    if (i == n - 1 || Down(a[i], start, end)) {
      while (down.size() >= 2 && !Down(down.back(), down[down.size() - 2], a[i])) {
        down.pop_back();
      }
      down.emplace_back(a[i]);
    }
  }
  long double res = 0;
  std::vector<Point> hull;
  for (auto u: up) {
    hull.emplace_back(u);
  }
  int sz = down.size();
  for (int i = sz - 2; i > 0; --i) {
    hull.emplace_back(down[i]);
  }
  sz = hull.size();
  for (int i = 0; i < sz; ++i) {
    int j = (i + 1) % sz;
    res += hull[i].dis(hull[j]);
  }
  printf("%Lf\n", res);
  return 0;
}
