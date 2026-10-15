#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> col(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  bool flag = true;
  std::array<int, 3> c{};
  auto Dfs = [&](auto &&self, int v) -> void {
    c[col[v]]++;
    for (auto to: g[v]) {
      if (col[to] == col[v]) flag = false;
      else if (!col[to]) {
        col[to] = col[v] % 2 + 1;
        self(self, to);
      }
    }
  };
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (col[i]) continue;
    flag = true;
    c = {};
    col[i] = 1;
    Dfs(Dfs, i);
    if (!flag) res += (c[1] + c[2]) * 1013;
    else res += std::max(c[1], c[2]) * 2026;
  }
  std::cout << res << '\n';
  return 0;
}
