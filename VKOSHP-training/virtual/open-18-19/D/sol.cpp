/**
 *    author:  feev1x
 *    created: 15.11.2024 09:34:03
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> d(n + 1);
  std::set<std::pair<int, int>> st, unus;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
    unus.emplace(d[i], i);
  }
  st.emplace(*--unus.end());
  while (!st.empty()) {
    int cur = (--st.end())->second;
    if (d[cur] <= 0) break;
    st.erase(--st.end());
    unus.erase({d[cur], cur});
    while (d[cur]--) {
      int to = (--unus.end())->second;
      unus.erase(--unus.end());
      st.erase({d[to], to});
      printf("%d %d\n", cur, to);
      d[to]--;
      st.emplace(d[to], to);
    }
  }
  return 0;
}
