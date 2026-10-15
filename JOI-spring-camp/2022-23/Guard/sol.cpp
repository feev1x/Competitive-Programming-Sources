#include <bits/stdc++.h>

#define int int64_t

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<int> s(n);
  std::vector<std::vector<int>> g(n);
  for (auto &u: s) std::cin >> u;
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v; --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<int> dp(n), boost(n);
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    for (auto to: g[v]) if (to != p) {
      self(self, to, v);
      dp[v] += dp[to] + s[to];
      if (s[v] >= s[to]) {
        if (boost[to] + s[to] > s[v]) boost[v] += boost[to] + s[to] - s[v];
        else dp[v] += s[v] - boost[to] - s[to];
      } else boost[v] += boost[to] + s[to] - s[v];
    }
  }; Dfs(Dfs, 0, 0);
  std::cout << dp[0] << '\n';
  return 0;
}
