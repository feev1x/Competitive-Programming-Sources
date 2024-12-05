/**
 *    author:  feev1x
 *    created: 03.12.2024 14:54:25
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  inline int dis(const Point &a) {
    return std::ceil(std::sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y)));
  }
};

int main() {
  std::freopen("moocast.in", "r", stdin);
  std::freopen("moocast.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<std::pair<Point, int>> cows(n);
  for (auto &[pt, p]: cows) {
    auto &[x, y] = pt;
    scanf("%d%d%d", &x, &y, &p);
  }
  std::vector<std::vector<int>> g(n);
  std::vector<bool> used(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      if (cows[i].first.dis(cows[j].first) <= cows[i].second) {
        g[i].emplace_back(j);
      }
    }
  }
  int cnt = 0;
  std::function<void(int)> Dfs = [&](int v) {
    used[v] = true;
    cnt++;
    for (auto to: g[v]) {
      if (used[to]) {
        continue;
      }
      Dfs(to);
    }
  };
  int res = 0;
  for (int i = 0; i < n; ++i) {
    std::fill(used.begin(), used.end(), false);
    cnt = 0;
    Dfs(i);
    res = std::max(res, cnt);
  }
  printf("%d\n", res);
  return 0;
}
