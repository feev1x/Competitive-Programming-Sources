/**
 *    author:  feev1x
 *    created: 21.12.2024 18:16:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; i64 sx, sy; std::cin >> n >> m >> sx >> sy;
  std::map<i64, std::set<i64>> mpx, mpy;
  for (int i = 0; i < n; ++i) {
    int x, y; std::cin >> x >> y;
    mpx[x].emplace(y);
    mpy[y].emplace(x);
  }
  std::set<std::pair<i64, i64>> st;
  std::map<char, std::pair<i64, i64>> mp;
  mp['U'] = {0, 1};
  mp['D'] = {0, -1};
  mp['L'] = {-1, 0};
  mp['R'] = {1, 0};
  for (int i = 0; i < m; ++i) {
    char ch; i64 c; std::cin >> ch >> c;
    i64 nx = sx + mp[ch].first * c;
    i64 ny = sy + mp[ch].second * c;
    if (sx == nx) {
      i64 u = std::min(sy, ny);
      i64 v = std::max(sy, ny);
      auto it = mpx[sx].lower_bound(u);
      while (!mpx[sx].empty() && it != mpx[sx].end() && *it <= v) {
        st.emplace(sx, *it);
        mpx[sx].erase(it);
        it = mpx[sx].lower_bound(u);
      }
    } else {
      i64 u = std::min(sx, nx);
      i64 v = std::max(sx, nx);
      auto it = mpy[sy].lower_bound(u);
      while (!mpy[sy].empty() && it != mpy[sy].end() && *it <= v) {
        st.emplace(*it, sy);
        mpy[sy].erase(it);
        it = mpy[sy].lower_bound(u);
      }
    }
    sx = nx, sy = ny;
  }
  std::cout << sx << ' ' << sy << ' ' << st.size() << '\n';
  return 0;
}
