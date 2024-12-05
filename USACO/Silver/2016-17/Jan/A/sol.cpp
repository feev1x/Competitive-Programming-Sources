/**
 *    author:  feev1x
 *    created: 03.12.2024 15:29:38
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("cowdance.in", "r", stdin);
  std::freopen("cowdance.out", "w", stdout);
  int n, tmx; scanf("%d%d", &n, &tmx);
  std::vector<int> d(n);
  for (auto &u: d) {
    scanf("%d", &u);
  }
  int l = 1, r = n, ans = n;
  while (l <= r) {
    int m = l + r >> 1;
    std::multiset<int> st;
    int tm = 0;
    for (auto u: d) {
      if (st.size() == m) {
        tm = *st.begin();
        st.erase(st.begin());
      }
      st.emplace(tm + u);
    }
    while (st.size()) {
      tm = *st.begin();
      st.erase(st.begin());
    }
    if (tm <= tmx) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
