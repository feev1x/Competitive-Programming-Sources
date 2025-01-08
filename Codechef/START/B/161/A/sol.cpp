/**
 *    author:  feev1x
 *    created: 20.11.2024 20:32:04
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> a(n), b(n);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    for (auto &u: b) {
      scanf("%d" ,&u);
    }
    std::set<std::pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
      st.emplace(a[i], i);
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      st.erase({a[i], i});
      int j = (--st.end())->second;
      int mx1 = std::max(a[i], b[i]);
      int mx2 = std::max(a[j], b[j]);
      if (mx1 > mx2) {
        flag = true;
        break;
      }
      st.emplace(a[i], i);
    }
    printf(flag ? "Yes\n" : "No\n");
  }
  return 0;
}
