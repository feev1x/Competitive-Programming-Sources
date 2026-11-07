#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> p(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<bool> dp(n + 1), rdp(n + 1);
  auto Dfs = [&](auto &&self, int v) -> void {
    for (auto to: g[v]) if (to != p[v]) {
      p[to] = v;
      self(self, to);
      if (!dp[to]) dp[v] = true;
    }
    if (!dp[v]) dp[v] = (g[v].size()) & 1;
  }; p[1] = 1, Dfs(Dfs, 1);
  auto Rert = [&](auto &&self, int v, bool flag) -> void {
    int cnt = 0;
    if (!flag) rdp[v] = true, cnt++;
    for (auto to: g[v]) if (to != p[v]) {
      if (!dp[to]) {
        rdp[v] = true, cnt++;
      }
    }
    if (!rdp[v]) {
      rdp[v] = (g[v].size()) & 1;
    }
    for (auto to: g[v]) if (to != p[v]) {
      if (cnt == 1) {
        if (dp[to]) {
          self(self, to, true);
        } else {
          self(self, to, (g[v].size()) & 1);
        }
      } else {
        if (cnt > 1) {
          self(self, to, true);
        } else {
          self(self, to, (g[v].size()) & 1);
        }
      }
    }
  }; p[1] = 1, Rert(Rert, 1, 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!rdp[i]) cnt++;
  }
  if (cnt) {
    std::cout << "Bob\n" << cnt << '\n';
    for (int i = 1; i <= n; ++i) {
      if (!rdp[i]) std::cout << i << ' ';
    }
    std::cout << '\n';
  } else {
    std::cout << "Alice\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
