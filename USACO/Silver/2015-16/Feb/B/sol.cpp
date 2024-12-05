/**
 *    author:  feev1x
 *    created: 02.12.2024 17:00:29
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  inline bool operator<(const Point a) {
    return x == a.x ? y < a.y : x < a.x;
  }
};

int main() {
  std::freopen("balancing.in", "r", stdin);
  std::freopen("balancing.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<Point> pt(n);
  std::map<int, bool> mp;
  for (auto &[x, y]: pt) {
    scanf("%d%d", &x, &y);
  }
  std::sort(pt.begin(), pt.end());
  int res = n;
  for (int i = 0; i < n; ++i) {
    int x = pt[i].x + 1;
    int l = 0, r = 1e6, ans = n;
    int tt = 100;
    while (tt--) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      if (m1 & 1) {
        m1++;
      }
      if (m2 & 1) {
        m2++;
      }
      int cnt1[2][2]{};
      int cnt2[2][2]{};
      for (int j = 0; j < n; ++j) {
        bool _i = pt[j].x > x, _j = pt[j].y > m1;
        cnt1[_i][_j]++;
        _j = pt[j].y > m2;
        cnt2[_i][_j]++;
      }
      int ans1{std::max({cnt1[0][1], cnt1[0][0], cnt1[1][1], cnt1[1][0]})};
      int ans2{std::max({cnt2[0][1], cnt2[0][0], cnt2[1][1], cnt2[1][0]})};
      ans = std::min({ans, ans1, ans2});
      if (ans1 > ans2) {
        l = m1;
      } else {
        r = m2;
      }
    }
    res = std::min(res, ans);
  }
  printf("%d\n", res);
  return 0;
}
