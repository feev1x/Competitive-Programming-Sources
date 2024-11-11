/**
 *    author:  feev1x
 *    created: 10.11.2024 13:03:28
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

struct Dsu {
  vector<int> sz, p, mn, mx;
  int n;
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    mn.resize(n + 1);
    mx.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    iota(mn.begin(), mn.end(), 0);
    iota(mx.begin(), mx.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
      mn[v] = min(mn[v], mn[u]);
      mx[v] = max(mx[v], mx[u]);
    }
  }
  inline int size(int v) {
    v = get(v);
    return sz[v];
  }
  inline int min_(int v) {
    v = get(v);
    return mn[v];
  }
  inline int max_(int v) {
    v = get(v);
    return mx[v];
  }
};

signed main() {
  int n; scanf("%d", &n);  
  Dsu d(n);
  char *S;
  while (scanf("%ms ", &S) == 1) {
    string s = S;
    if (s == "union") {
      int u, v; scanf("%d%d", &u, &v);
      d.unite(u, v);
    } else if (s == "get") {
      int u; scanf("%d", &u);
      printf("%d %d %d\n", d.min_(u), d.max_(u), d.size(u));
    } else {
      break;
    }
  }
  free(S);
  return 0;
}
