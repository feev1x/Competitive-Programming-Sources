/**
 *    author:  feev1x
 *    created: 25.10.2024 12:14:21
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

vector<int> ans;
vector<vector<int>> g;

class Dsu {
  vector<int> sz, p;
  vector<vector<int>> comp;
  int n;
 public:
  Dsu(int _n) : n(_n) {
    p.resize(n + 1);
    comp.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 0; i <= n; ++i) comp[i].emplace_back(i);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) swap(u, v);
      for (auto nw: comp[u]) {
        for (auto i: g[nw]) {
          if (get(i) == v) {
            ans[nw]++;
            ans[i]++;
          }
        }
      }
      while (!comp[u].empty()) {
        comp[v].emplace_back(comp[u].back());
        comp[u].pop_back();
      }
      p[u] = v;
      sz[v] += sz[u];
    }
  }
  inline int size(int v) {
    return sz[get(v)];
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k; cin >> n >> m >> k;
  g.resize(n + 1);
  ans.resize(n + 1);
  map<int, map<int, bool>> mp;
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    mp[u][v] = mp[v][u] = true;
  }
  Dsu d(n);
  for (int i = 0; i < k; ++i) {
    int a, b; cin >> a >> b;
    d.unite(a, b);
  }
  int q; cin >> q;
  while (q--) {
    char ch; cin >> ch;
    if (ch == '?') {
      int v; cin >> v;
      cout << ans[v] << '\n';
    } else if (ch == 'T') {
      int a, b; cin >> a >> b;
      d.unite(a, b);
    } else {
      int a, b; cin >> a >> b;
      g[a].emplace_back(b);
      g[b].emplace_back(a);
      if (d.get(a) == d.get(b)) {
        ans[a]++;
        ans[b]++;
      }
      mp[a][b] = mp[b][a] = true;
    }
  }
  return 0;
}
