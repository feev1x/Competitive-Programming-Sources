/**
 *    author:  feev1x
 *    created: 20.11.2024 09:46:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  int a, b; scanf("%d%d", &a, &b);
  std::map<char, std::pair<int, int>> dir;
  std::map<std::pair<int, int>, std::pair<int, int>> rot;
  dir['N'] = {0, 1};
  dir['S'] = {0, -1};
  dir['W'] = {-1, 0};
  dir['E'] = {1, 0};
  rot[{0, 1}] = {1, 0};
  rot[{0, -1}] = {-1, 0};
  rot[{1, 0}] = {0, -1};
  rot[{-1, 0}] = {0, 1};
  auto Check = [&](int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && (x != a || y != b);
  };
  while (q--) {
    int x, y; scanf("%d%d", &x, &y);
    char ch; scanf(" %c", &ch);
    std::set<std::pair<int, int>> st;
    st.emplace(x, y);
    int cx, cy;
    std::tie(cx, cy) = dir[ch];
    while (true) {
      if (!Check(x + cx, y + cy) || st.find({x + cx, y + cy}) != st.end()) {
        std::tie(cx, cy) = rot[{cx, cy}];
      }
      if (!Check(x + cx, y + cy) || st.find({x + cx, y + cy}) != st.end()) {
        break;
      }
      x += cx, y += cy;
      st.emplace(x, y);
    }
    printf("%d\n", (int)st.size());
  }
  return 0;
}
