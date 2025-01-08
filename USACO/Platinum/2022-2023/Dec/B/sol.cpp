/**
 *    author:  feev1x
 *    created: 04.01.2025 10:09:41
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::set<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace(v);
    g[v].emplace(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int min = *g[i].begin(), old = g[min].size();
    for (auto to: g[i]) {
      if (to == min) {
        continue;
      }

    }
  }
  std::cout << cnt << '\n';
  return 0;
}
