/*
 *   author:  feev1x
 *    created: 07.01.2025 11:47:17
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> p(n + 1);
  std::vector<std::vector<int>> g(n + 1);
  int mxsz = 0, list = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
    g[p[i]].emplace_back(i);
    mxsz = std::max(mxsz, (int)g[p[i]].size());
  }
  std::vector<i64> op_off(n + 1), sz(n + 1, 1), op_on(n + 1);
  auto Dfs = [&](auto &&self, int v) -> void {
    std::vector<i64> ar;
    for (auto to: g[v]) {
      self(self, to);
      ar.emplace_back(op_off[to] - op_on[to] + sz[to]);
      sz[v] += sz[v];
      op_off[v] += op_off[to];
    }
    std::sort(ar1.begin(), ar1.end(), std::greater<>());
    if (ar.size() <= 1) {
      op_off[v] += sz[v] * 2;
      op_on[v] = op_off[v] - sz[v];
    } else {
      for (int i = 0; i < std::min(int(ar.size()), 2); ++i) {
        if (i == 0) {
          op_off[v] -= ar[i];
          op_on[v] -= ar[i];
        } else {
          op_off[v] -= ;
        }
      }
      i64 on = op_on[v], off = op_off[v];
    }
  };
  Dfs(Dfs, 1);
  for (int i = 1; i <= n; ++i) {
    if (g[i].empty()) {
      list++;
    }
    std::cerr << i << " ON: " << op_on[i] << " OFF: " << op_off[i] << '\n';
  }
  i64 res = op_off[1];
  std::cout << res << '\n';
  return 0;
}
