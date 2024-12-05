/**
 *    author:  feev1x
 *    created: 02.12.2024 19:12:06
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Dsu {
  std::vector<int> sz, p;
  int n;
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        std::swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

int main() {
  std::freopen("closing.in", "r", stdin);
  std::freopen("closing.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  Dsu d(n);
  std::vector<int> order(n);
  for (auto &u: order) {
    scanf("%d", &u);
  }
  std::deque<std::string> ans;
  std::vector<bool> open(n + 1);
  std::reverse(order.begin(), order.end());
  int cnt = 0;
  for (auto u: order) {
    open[u] = true;
    cnt++;
    for (auto to: g[u]) {
      if (open[to]) {
        d.unite(u, to);
      }
    }
    ans.emplace_front(d.sz[d.get(u)] == cnt ? "YES" : "NO");
  }
  for (auto u: ans) {
    printf("%s\n", u.c_str());
  }
  return 0;
}
