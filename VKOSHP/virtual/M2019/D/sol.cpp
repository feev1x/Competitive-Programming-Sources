/**
 *    author:  feev1x
 *    created: 12.11.2024 09:02:32
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    g[v].emplace_back(u, w);
  }
  std::set<std::pair<int, int>> q;
  std::vector<int> dis(n + 1);
  dis[1] = 2e9;
  q.emplace(dis[1], 1);
  while (!q.empty()) {
    int cur = (--q.end())->second;
    q.erase(--q.end());
    for (auto [to, w]: g[cur]) {
      if (dis[to] < std::min(dis[cur], w)) {
        q.erase({dis[to], to});
        dis[to] = std::min(dis[cur], w);
        q.emplace(dis[to], to);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    printf("%d\n", dis[i] == 0 ? -1 : dis[i]);
  }
  return 0;
}
