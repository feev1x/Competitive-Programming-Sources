/**
 *    author:  feev1x
 *    created: 13.11.2024 08:53:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 w; scanf("%lld", &w);
  int n; scanf("%d", &n);
  std::vector<i64> g(n), b(n);
  std::set<std::tuple<i64, i64, int>> st;
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &g[i], &b[i]);
    st.emplace(b[i], g[i], i);
  }
  std::set<std::pair<i64, int>> can;
  std::vector<int> used;
  i64 gold = 0;
  while (gold < w) {
    while (!st.empty() && std::get<0>(*st.begin()) <= gold) {
      can.emplace(std::get<1>(*st.begin()), std::get<2>(*st.begin()));
      st.erase(st.begin());
    }
    if (can.empty() && gold < w) {
      break;
    }
    gold += (--can.end())->first;
    used.emplace_back((--can.end())->second);
    can.erase(--can.end());
  }
  if (gold < w) {
    printf("-1\n");
    exit(0);
  }
  printf("%d\n", (int)used.size());
  for (auto u: used) {
    printf("%d ", u + 1);
  }
  printf("\n");
  return 0;
}
