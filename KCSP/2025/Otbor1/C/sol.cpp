/**
 *    author:  feev1x
 *    created: 08.12.2024 11:20:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::set<std::pair<int, int>> lx, rx, ly, ry;
  std::set<int> st;
  for (int i = 1; i <= n; ++i) {
    int xl, xr, yl, yr; scanf("%d%d%d%d", &xl, &xr, &yl, &yr);
    lx.emplace(xl, i);
    ly.emplace(yl, i);
    rx.emplace(xr, i);
    ry.emplace(yr, i);
    st.emplace(i);
  }
  for (int i = 1; i <= m; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    std::set<std::pair<int, int>> del;
    for (auto it = lx.upper_bound({x, n + 1}); it != lx.end(); ++it) {
      del.emplace(*it);
    }
    for (auto u: del) {
      lx.erase(u);
      st.erase(u.second);
    }
    std::set<std::pair<int, int>>().swap(del);
    for (auto it = ly.upper_bound({y, n + 1}); it != ly.end(); ++it) {
      del.emplace(*it);
    }
    for (auto u: del) {
      ly.erase(u);
      st.erase(u.second);
    }
    std::set<std::pair<int, int>>().swap(del);
    if (rx.lower_bound({x, -1}) != rx.begin()) {
      for (auto it = --rx.lower_bound({x, -1}); ; --it) {
        del.emplace(*it);
        if (it == rx.begin()) {
          break;
        }
      }
      for (auto u: del) {
        rx.erase(u);
        st.erase(u.second);
      }
      std::set<std::pair<int, int>>().swap(del);
    }
    if (ry.lower_bound({y, -1}) != ry.begin()) {
      for (auto it = --ry.lower_bound({y, -1}); ; --it) {
        del.emplace(*it);
        if (it == ry.begin()) {
          break;
        }
      }
      for (auto u: del) {
        ry.erase(u);
        st.erase(u.second);
      }
      std::set<std::pair<int, int>>().swap(del);
    }
    printf("%d ", (int)st.size());
  }
  printf("\n");
  return 0;
}
