/**
 *    author:  feev1x
 *    created: 05.01.2025 15:03:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<i64> h(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> h[i];
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  i64 nd = (i64)accumulate(h.begin(), h.end(), 0ll) / n;
  std::vector<int> sz(n + 1, 1);
  std::vector<i64> sum(n + 1);
  auto Init = [&](auto &&self, int v, int p) -> void {
    sum[v] = h[v];
    for (auto to: g[v]) {
      if (to == p) {
        continue;
      }
      self(self, to, v);
      sum[v] += sum[to];
      sz[v] += sz[to];
    }
  };
  Init(Init, 1, 0);
  std::vector<std::tuple<int, int, i64>> ans;
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    for (auto to: g[v]) {
      if (to == p) {
        continue;
      }
      i64 rl = nd * sz[to];
      if (sum[to] > rl) {
        self(self, to, v);
        ans.emplace_back(to, v, h[to] - nd);
        assert(sum[to] - (h[to] - nd) == rl);
        h[v] += h[to] - nd;
        h[to] = nd;
        sum[to] = rl;
      } else if (sum[to] == rl) {
        self(self, to, v);
      }
    }
    for (auto to: g[v]) {
      if (to == p) {
        continue;
      }
      i64 rl = nd * sz[to];
      if (sum[to] < rl) {
        ans.emplace_back(v, to, (rl - sum[to]));
        h[to] += (rl - sum[to]);
        h[v] -= (rl - sum[to]);
        assert(h[v] >= nd);
        sum[to] = rl;
        self(self, to, v);
      }
    }
  };
  Dfs(Dfs, 1, 0);
  std::cout << ans.size() << '\n';
  for (auto [A, B, C]: ans) {
    std::cout << A << ' ' << B << ' ' << C << '\n';
  }
  return 0;
}
