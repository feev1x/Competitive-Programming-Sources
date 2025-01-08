/**
 *    author:  feev1x
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
  for (int i = 2; i <= n; ++i) {
    std::cin >> p[i];
    g[p[i]].emplace_back(i);
  }
  std::vector<i64> op(n + 1), sz(n + 1, 1);
  auto Dfs = [&](auto &&self, int v) -> void {
    std::vector<i64> ar;
    for (auto to: g[v]) {
      self(self, to);
      ar.emplace_back(sz[to]);
      sz[v] += sz[to];
      op[v] += op[to];
    }
    std::sort(ar.begin(), ar.end(), std::greater<>());
    op[v] += sz[v] * 2;
    for (int i = 0; i < std::min(int(ar.size()), 2); ++i) {
      op[v] -= 2 * ar[i];
    }
  };
  Dfs(Dfs, 1);
  std::cout << op[1] << '\n';
  return 0;
}

