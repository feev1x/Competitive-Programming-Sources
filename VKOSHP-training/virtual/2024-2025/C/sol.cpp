/**
 *    author:  feev1x
 *    created: 10.12.2024 16:36:46
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> g(n + 1), t(n + 1);
  std::vector<std::set<int>> not_t(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    not_t[u].emplace(v);
    not_t[v].emplace(u);
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    t[u].emplace_back(v);
    t[v].emplace_back(u);
    not_t[u].erase(v);
    not_t[v].erase(u);
  }
  std::string s(n, '0');
  std::vector<int> tin(n + 1), tout(n + 1);
  auto Init = [&](auto &&Init, int v, int p) -> void {
    tin[v] = tout[p];
    tout[v] = tin[v] + 1;
    for (auto to: t[v]) {
      if (to == p) {
        continue;
      }
      Init(to, v);
      tout[v] = tout[to] + 1;
    }
  };
  auto IsPar = [&](int v, int p) {
    return tin[p] <= tin[v] && tout[v] <= tout[p];
  };
  tout[0] = 1;
  Init(Init, 1, 0);
  int cnt_g = 0, cnt_b = 0, cnt_pg = 0, cnt_pb = 0;
  for (int v = 1; v <= n; ++v) {
    for (auto to: g[v]) {
      if (to > v) {
        break;
      }
      cnt_g += IsPar(to, v);
      cnt_b += !IsPar(to, v);
    }
  }
  auto Dfs = [&](auto &&Dfs, int v, int p) -> void {
    for (auto to: 
  };
  return 0;
}
