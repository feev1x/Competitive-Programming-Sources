#include <bits/stdc++.h>

struct Dsu {
  std::vector<int> p, sz;
  int n;
  Dsu(int n) : n(n) {
    p.resize(n);
    sz.assign(n, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline bool check(int u, int v) {
    return get(u) == get(v);
  }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      sz[v] += sz[u];
      p[u] = v;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::string> c(n);
  for (auto &u: c) std::cin >> u;
  Dsu d(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (c[i][j] == '0') d.unite(i, j);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (i != j) {
      if (d.check(i, j) && c[i][j] == '1') {
        std::cout << "NO\n";
        exit(0);
      }
      if (d.check(i, j)) c[i][j] = '0';
      else c[i][j] = '1';
    }
  std::cout << "YES\n";
  for (auto u: c) std::cout << u << '\n';
  return 0;
}
