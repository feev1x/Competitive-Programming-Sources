#include <bits/stdc++.h>

constexpr int N = 20;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> tin(n + 1), tout(n + 1);
  std::vector<std::array<int, N>> anc(n + 1);
  for (int i = 1; i <= n; ++i) {
    int k; std::cin >> k;
    for (int j = 0; j < k; ++j) {
      int u; std::cin >> u;
      g[i].emplace_back(u);
      anc[u][0] = i;
    }
  }
  anc[1][0] = 1;
  int _t = 0;
  auto Dfs = [&](auto &&self, int v) -> void {
    tin[v] = ++_t;
    for (int i = 1; i < N; ++i) anc[v][i] = anc[anc[v][i - 1]][i - 1];
    for (auto to: g[v]) self(self, to);
    tout[v] = ++_t;
  }; Dfs(Dfs, 1);
  auto IsPar = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };
  auto Lca = [&](int u, int v) {
    if (IsPar(u, v)) return u;
    for (int i = N - 1; i >= 0; --i) if (!IsPar(anc[u][i], v)) u = anc[u][i];
    return anc[u][0];
  };
  std::set<std::pair<int, int>> stl, str;
  int q; std::cin >> q;
  while (q--) {
    int t, v; std::cin >> t >> v;
    if (t == 1) stl.emplace(tin[v], v), str.emplace(tout[v], v);
    else stl.erase({tin[v], v}), str.erase({tout[v], v});
    if (stl.empty()) {
      std::cout << "0\n";
      continue;
    }
    std::cout << Lca(stl.begin()->second, str.rbegin()->second) << '\n';
  }
  return 0;
}
