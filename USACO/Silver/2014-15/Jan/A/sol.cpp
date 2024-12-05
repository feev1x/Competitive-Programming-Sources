/**
 *    author:  feev1x
 *    created: 25.11.2024 19:57:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("stampede.in", "r", stdin);
  std::freopen("stampede.out", "w", stdout);
  int n; scanf("%d", &n);
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    int x, y, d; scanf("%d%d%d", &x, &y, &d);
    int l = (-x - 1) * d, r = l + d;
    st.emplace(l, y);
    st.emplace(r, -y);
  }
  std::set<int> nw, ans;
  int ls = -1;
  for (auto [tm, y]: st) {
    if (ls < tm && nw.size()) {
      ans.emplace(*nw.begin());
    }
    if (y < 0) {
      nw.erase(-y);
    } else {
      nw.emplace(y);
    }
    ls = tm;
  }
  if (nw.size()) {
    ans.emplace(*nw.begin());
  }
  printf("%d\n", (int)ans.size());
  return 0;
}
