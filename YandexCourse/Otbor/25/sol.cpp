#include <bits/stdc++.h>

constexpr int MOD = 998244353;

struct Dsu {
  std::vector<int> sz, p, e;
  int n, cnt;
  Dsu(int n) : n(n), cnt(n) {
    p.resize(n + 1);
    e.resize(n + 1);
    sz.assign(n + 1, 1);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
      e[v] += e[u];
      cnt--;
    }
    e[v]++;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  Dsu d(n);
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    d.unite(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    if (d.e[d.get(i)] != d.sz[d.get(i)]) {
      std::cout << "0\n";
      exit(0);
    }
  }
  int res = 1, a = 2;
  while (d.cnt) {
    if (d.cnt & 1) res = res * 1LL * a % MOD;
    a = a * 1LL * a % MOD;
    d.cnt >>= 1;
  }
  std::cout << res << '\n';
  return 0;
}
