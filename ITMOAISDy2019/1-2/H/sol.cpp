/**
 *    author:  feev1x
 *    created: 10.11.2024 14:40:10
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

struct Dsu {
  std::vector<int> sz, p, sum, all;
  int n;
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    sum.resize(n + 1);
    p.resize(n + 1);
    all.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  }
  inline std::pair<int, int> get(int v, int x = 0) {
    if (v == p[v]) {
      all[v] += x;
      sum[v] += x;
    debug(v, sum[v], all[v]);
      return {v, 0};
    }
    auto pr = get(p[v], x);
    p[v] = pr.first;
    all[v] += pr.second;
    sum[v] = all[v] + all[p[v]];
    debug(v, sum[v], all[v]);
    return {p[v], all[v]};
  }
  inline void unite(int u, int v) {
    auto pr = get(u);
    u = pr.first;
    pr = get(v);
    v = pr.first;
    if (u != v) {
      if (sz[u] > sz[v]) {
        std::swap(u, v);
      }
      p[u] = v;
      all[u] -= all[v];
      sz[v] += sz[u];
    }
  }
  inline void add(int v, int x) {
    get(v, x);
  }
  inline int val(int v) {
    get(v);
    return sum[v];
  }
};

signed main() {
  int n, m; scanf("%d%d", &n, &m);
  Dsu d(n);
  char S[5];
  while (m--) {
    scanf("%s", S);
    std::string s = S;
    if (s == "add") {
      int x, v; scanf("%d%d", &x, &v);
      d.add(x, v);
    } else if (s == "join") {
      int x, y; scanf("%d%d", &x, &y);
      d.unite(x, y);
    } else {
      int x; scanf("%d", &x);
      printf("%d\n", d.val(x));
    }
  }
  return 0;
}
