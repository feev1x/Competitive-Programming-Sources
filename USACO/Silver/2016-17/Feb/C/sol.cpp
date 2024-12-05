/**
 *    author:  feev1x
 *    created: 04.12.2024 12:58:57
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  inline bool operator<(const Point &a) {
    return x == a.x ? y < a.y : x < a.x;
  }
  inline void input() {
    scanf("%d%d", &x, &y);
  }
};

inline bool operator<(const Point &a, const Point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int main() {
  std::freopen("countcross.in", "r", stdin);
  std::freopen("countcross.out", "w", stdout);
  int n, k, r; scanf("%d%d%d", &n, &k, &r);
  std::map<Point, std::map<Point, bool>> mp;
  std::vector<Point> a(k);
  for (int i = 0; i < r; ++i) {
    Point p1, p2; p1.input(), p2.input();
    mp[p1][p2] = mp[p2][p1] = true;
  }
  auto Check = [&](Point p) {
    return 1 <= p.x && p.x <= n && 1 <= p.y && p.y <= n;
  };
  int dx[]{-1, 1, 0, 0};
  int dy[]{0, 0, -1, 1};
  std::vector can(k, std::vector(n + 1, std::vector(n + 1, false)));
  for (int i = 0; i < k; ++i) {
    a[i].input();
    can[i][a[i].x][a[i].y] = true;
    std::queue<Point> q;
    q.emplace(a[i]);
    while (q.size()) {
      auto p = q.front();
      q.pop();
      for (int j = 0; j < 4; ++j) {
        Point p1(p.x + dx[j], p.y + dy[j]);
        if (Check(p1) && !can[i][p1.x][p1.y] && !mp[p][p1]) {
          can[i][p1.x][p1.y] = true;
          q.emplace(p1);
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      cnt += !can[i][a[j].x][a[j].y];
    }
  }
  printf("%d\n", cnt);
  return 0;
}
