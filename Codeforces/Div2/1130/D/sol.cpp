#include <bits/stdc++.h>

inline void solve() {
  int k; std::cin >> k;
  std::vector<std::vector<std::vector<int>>> g(k + 1);
  std::vector<std::vector<bool>> col(k + 1);
  std::vector<std::array<int, 2>> cnt(k + 1);
  std::vector<std::array<int, 2>> c(k + 1);
  std::vector<bool> mxc(k + 1);
  int idx = -1;
  for (int t = 1; t <= k; ++t) {
    int n; std::cin >> n;
    g[t].resize(n + 1);
    col[t].resize(n + 1);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2));
    std::vector<std::vector<int>> ver(n + 1, std::vector<int>(2));
    for (int i = 1; i < n; ++i) {
      int u, v; std::cin >> u >> v;
      g[t][u].emplace_back(v);
      g[t][v].emplace_back(u);
    }
    auto Dfs = [&](auto &&self, int v, int p) -> void {
      dp[v][1] = 1;
      for (auto to: g[t][v]) if (to != p) {
        self(self, to, v);
        if (dp[to][1] > dp[to][0]) {
          dp[v][0] += dp[to][1];
          ver[v][0] = to;
        } else {
          dp[v][0] += dp[to][0];
          ver[v][0] = ver[to][0];
        }
        dp[v][1] += dp[to][0];
        ver[v][1] = to;
      }
    }; Dfs(Dfs, 1, 1);
    if (dp[1][0] > dp[1][1]) {
      c[t][0] = 1;
      c[t][1] = ver[1][0];
    } else {
      c[t][0] = ver[1][1];
      c[t][1] = 1;
    }
    if (n > 1) idx = t;
  }
  if (idx == -1) {
    idx = 1;
    c[1][0] = 1;
  }
  for (int t = 1; t <= k; ++t) if (t != idx) {
    std::cout << idx << ' ' << c[idx][0] << ' ' << t << ' ' << c[t][1] << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
