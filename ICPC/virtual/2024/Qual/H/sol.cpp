/**
 *    author:  feev1x
 *    created: 13.11.2024 09:07:05
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Dsu {
  std::vector<int> sz, p;
  std::vector<bool> os;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n + 1);
    os.resize(n + 1);
    sz.assign(n + 1, 1);
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
      if (os[u]) {
        std::swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
    }
  }
  inline void oso(int u) {
    u = get(u);
    os[u] = true;
  }
  inline int size(int u) {
    return sz[get(u)];
  }
};

int main() {
  int n; scanf("%d", &n);
  std::vector<int> b(n);
  Dsu d(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    if (b[i] == 0) {
      d.oso(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i] != 0) {
      d.unite(i, b[i]);
    }
  }
  int opt = -1, mx = -1;
  for (int v = 1; v <= n; ++v) {
    if (d.size(v) > mx) {
      opt = d.get(v);
      mx = d.size(v);
    }
  }
  printf("%d %d\n", opt, mx);
  return 0;
}
