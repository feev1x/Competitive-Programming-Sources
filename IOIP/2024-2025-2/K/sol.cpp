/**
 *    author:  feev1x
 *    created: 06.12.2024 12:25:55
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1001;

int main() {
  int n, w; scanf("%d%d", &n, &w);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  a.emplace(a.begin(), 0);
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(w));
  for (int i = 1; i < n; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::function<void(int, int)> Dfs = [&](int v, int p) {
    dp[v][0] = true;
    dp[v][a[v]] = true;
    for (auto to: g[v]) {
      if (to == p) {
        continue;
      }
      Dfs(to, v);
      for (int i = 1; i <= w; ++i) {
        if (dp[to][i]) {
        }
      }
    }
  };
  return 0;
}
