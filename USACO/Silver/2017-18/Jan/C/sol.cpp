/**
 *    author:  feev1x
 *    created: 19.12.2024 10:26:49
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("mootube.in", "r", stdin);
  std::freopen("mootube.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v, w; std::cin >> u >> v >> w;https://youtu.be/EmtPXRLsZNo
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  std::vector a(n + 1, std::vector<int>(n + 1));
  int i;
  auto Dfs = [&](auto &&self, int v, int p, int edge) -> void {
    a[i][v] = edge;
    for (auto [to, w]: g[v]) {
      if (to == p) {
        continue;
      }
      self(self, to, v, std::min(edge, w));
    }
  };
  for (i = 1; i <= n; ++i) {
    Dfs(Dfs, i, -1, 1e9);
    std::sort(a[i].begin(), a[i].end());
  }
  while (q--) {
    int k, u; std::cin >> k >> u;
    int j = std::lower_bound(a[u].begin(), a[u].end(), k) - a[u].begin();
    if (j > n) j = n;
    std::cout << n - j << '\n';
  }
  return 0;
}
