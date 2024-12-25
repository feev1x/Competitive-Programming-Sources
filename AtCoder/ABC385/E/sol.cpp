/**
 *    author:  feev1x
 *    created: 21.12.2024 18:39:54
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int res = n + 1;
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    std::vector<int> all;
    for (auto to: g[v]) {
      all.emplace_back((int)g[to].size());
    }
    std::sort(all.begin(), all.end(), std::greater<>());
    for (int i = 0; i < all.size(); ++i) {
      res = std::min(res, n - ((i + 1) * all[i] + 1));
    }
    for (auto to: g[v]) {
      if (to == p) {
        continue;
      }
      self(self, to, v);
    }
  };
  Dfs(Dfs, 1, 0);
  std::cout << res << '\n';
  return 0;
}
