/**
 *    author:  feev1x
 *    created: 21.10.2024 20:40:06
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

class Dsu {
  vector<int> sz, p;
  int n;
 public:
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  };
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  Dsu d(n);
  vector<bool> used(n + 1);
  vector<tuple<int, int, int>> e;
  for (int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    e.emplace_back(w, u, v);
  }
  sort(e.begin(), e.end(), greater<>());
  int res = 0;
  for (auto [w, u, v]: e) {
    if (used[d.get(u)] && used[d.get(v)]) continue;
    if (!used[d.get(u)] && used[d.get(v)]) {
      used[d.get(u)] = true;
    } else if (used[d.get(u)] && !used[d.get(v)]) {
      used[d.get(v)] = true;
    } else if (d.get(u) == d.get(v)) {
      used[d.get(u)] = true;
    } else {
      d.unite(u, v);
    }
    res += w;
  }
  cout << res << '\n';
  return 0;
}
