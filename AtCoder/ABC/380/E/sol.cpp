/**
 *    author:  feev1x
 *    created: 16.11.2024 18:38:59
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Dsu {
  std::vector<int> p, sz, l, r, col, cnt;
  int n;
  Dsu(int _n) : n(_n) {
    p.resize(n + 1);
    cnt.assign(n + 1, 1);
    col.resize(n + 1);
    sz.assign(n + 1, 1);
    l.resize(n + 1);
    r.resize(n + 1);
    std::iota(p.begin(), p.end(), 0);
    std::iota(col.begin(), col.end(), 0);
    std::iota(r.begin(), r.end(), 0);
    std::iota(l.begin(), l.end(), 0);
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
      l[v] = std::min(l[v], l[u]);
      r[v] = std::max(r[v], r[u]);
      assert(col[u] == col[v]);
    }
  }
  inline int left(int u) {
    u = get(u);
    return l[u];
  }
  inline int right(int u) {
    u = get(u);
    return r[u];
  }
  inline int color(int u) {
    u = get(u);
    return col[u];
  }
  inline void paint(int u, int c) {
    u = get(u);
    cnt[col[u]] -= sz[u];
    col[u] = c;
    cnt[c] += sz[u];
  }
  inline int count(int c) {
    return cnt[c];
  }
};

int main() {
  int n, q; scanf("%d%d", &n, &q);
  Dsu d(n);
  while (q--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int x, c; scanf("%d%d", &x, &c);
      d.paint(x, c);
      if (d.left(x) > 1 && d.color(d.left(x) - 1) == c) {
        d.unite(x, d.left(x) - 1);
      }
      if (d.right(x) < n && d.color(d.right(x) + 1) == c) {
        d.unite(x, d.right(x) + 1);
      }
    } else {
      int c; scanf("%d", &c);
      printf("%d\n", d.count(c));
    }
  }
  return 0;
}
