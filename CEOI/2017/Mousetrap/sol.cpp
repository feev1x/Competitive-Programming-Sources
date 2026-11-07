#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, t, m; std::cin >> n >> t >> m;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<int> p(n + 1), cs(n + 1), dp(n + 1, n + 5), tin(n + 1), tout(n + 1);
  int _t = 0;
  auto Dfs = [&](auto &&self, int v) -> void {
    tin[v] = ++_t;
    for (auto to: g[v]) if (to != p[v]) p[to] = v, self(self, to);
    tout[v] = ++_t;
  }; p[m] = m, Dfs(Dfs, m);
  auto Df = [&](auto &&self, int v, int cost) -> void {
    cs[v] = cost;
    for (auto to: g[v]) if (to != p[v]) {
      self(self, to, cost + int(g[v].size()) - 1);
    }
  };
  for (auto to: g[t]) if (to != p[t]) Df(Df, to, 1);
  int cnt = 0;
  for (int v = p[t], ls = t; ls != m; ls = v, v = p[v]) {
    cs[v] = cnt;
    for (auto to: g[v]) if (to != p[v] && to != ls) {
      cnt++;
    }
    for (auto to: g[v]) if (to != p[v] && to != ls) {
      Df(Df, to, cnt);
    }
  }
  g[m].emplace_back(m);
  auto Calc = [&](auto &&self, int v, int left) -> void {
    if (v == t) {
      dp[v] = 0;
      return;
    }
    std::vector<int> ar, ar2;
    int idx = -1;
    bool isd = tin[v] <= tin[t] && tout[t] <= tout[v];
    for (auto to: g[v]) if (to != p[v]) {
      if (tin[to] > tin[t] || tout[t] > tout[to]) {
        self(self, to, 1);
        ar.emplace_back(dp[to]);
      } else {
        self(self, to, std::max(1, left - ((int)g[v].size() - 2) + 1));
        idx = to;
      }
      ar2.emplace_back(dp[to]);
    }
    if (ar2.empty()) return dp[v] = cs[v], void();
    std::sort(ar.begin(), ar.end(), std::greater<>());
    if (isd) {
      if (left >= (int)ar.size()) {
        dp[v] = std::min(dp[v], dp[idx] + (int)ar.size());
      } else {
        dp[v] = std::min(dp[v], std::max(dp[idx] + left, ar[left]));
      }
    } else {
      dp[v] = std::min(dp[v], ar[std::min(left, (int)ar.size() - 1)]);
      if (left >= (int)ar.size()) dp[v] = std::min(dp[v], cs[v] + (int)ar.size());
    }
  }; Calc(Calc, m, 1);
  int l = 0, r = n * 3, ans = -1;
  while (l <= r) {
    int M = l + r >> 1;
    int v = m, left = 0, nw = 0;
    bool flag = true;
    while (v != t) {
      left++;
      int idx = -1, add = 0;
      for (auto to: g[v]) if (to != p[v]) {
        if (tin[to] > tin[t] || tout[t] > tout[to]) {
          if (nw + dp[to] > M) left--, add++;
        } else {
          idx = to;
        }
      }
      nw += add;
      if (left < 0) {
        flag = false;
        break;
      }
      v = idx;
    }
    if (flag && nw <= M) r = M - 1, ans = M;
    else l = M + 1;
  }
  std::cout << ans << '\n';
  return 0;
}
