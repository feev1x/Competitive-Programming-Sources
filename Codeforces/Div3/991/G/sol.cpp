/**
 *    author:  feev1x
 *    created: 05.12.2024 22:21:10
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<std::vector<int>> g(n + 1), vl(n + 1);
    std::vector<int> max(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    int mx = 1;
    std::function<void(int, int)> Dfs = [&](int v, int p) {
      for (auto to: g[v]) {
        if (to == p) {
          continue;
        }
        Dfs(to, v);
        max[v] = std::max(max[v], max[to]);
        vl[v].emplace_back(max[to]);
      }
      int sz = g[v].size();
      if (p != -1) {
        sz--;
      }
      if (sz) {
        max[v] += sz - 1;
      }
      std::sort(vl[v].begin(), vl[v].end(), std::greater<>());
      int val = max[v];
      if (p != -1) val++;
      mx = std::max(mx, val);
      mx = std::max(mx, (int)g[v].size());
      if (sz >= 2) {
        val = vl[v][0] + vl[v][1];
        if (sz > 2) {
          val += sz - 2;
        }
        if (p != -1) {
          val++;
        }
        mx = std::max(mx, val);
      }
      max[v] = std::max(max[v], sz);
    };
    Dfs(1, -1);
    printf("%d\n", mx);
  }
  return 0;
}
