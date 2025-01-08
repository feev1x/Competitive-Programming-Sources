/**
 *    author:  feev1x
 *    created: 04.01.2025 21:31:12
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, m, q; std::cin >> n >> m >> q;
    std::vector<std::tuple<int, int, int>> e;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::vector<bool>> can(n + 1, std::vector<bool>(n + 1));
    for (int i = 0; i < m; ++i) {
      int u, v, w; std::cin >> u >> v >> w;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
      e.emplace_back(w, u, v);
    }
    std::sort(e.begin(), e.end(), std::greater<>());
    for (int i = 1; i <= n; ++i) {
      auto Dfs = [&](auto &&self, int v) -> void {
        can[i][v] = true;
        for (auto to: g[v]) {
          if (can[i][to]) {
            continue;
          }
          self(self, to);
        }
      };
      Dfs(Dfs, i);
    }
    while (q--) {
      int a, b, k; std::cin >> a >> b >> k;
      for (auto [w, u, v]: e) {
        if (can[a][u] && can[v][b]) {
          if (!--k) {
            std::cout << w << " \n"[!q];
            break;
          }
        }
      }
    }
  }
  return 0;
}
