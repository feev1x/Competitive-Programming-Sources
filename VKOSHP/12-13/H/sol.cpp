/**
 *    author:  feev1x
 *    created: 17.10.2024 17:33:06
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
  }
  inline int Get(int v) {
    return v == p[v] ? v : p[v] = Get(p[v]);
  }
  inline bool Unite(int u, int v) {
    u = Get(u);
    v = Get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
      return true;
    }
    return false;
  }
  inline int size(int u) {
    u = Get(u);
    return sz[u];
  }
};

signed main() {
//  freopen("odd.in", "r", stdin);
//  freopen("odd.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<pair<int, int>> e(m + 1);
  map<int, map<int, int>> ind;
  vector<vector<int>> g(n + 1);
  Dsu d(n);
  for (int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    e[i] = {u, v};
    if (d.Unite(u, v)) {
      ind[u][v] = ind[v][u] = i;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    if (d.size(i) & 1) {
      flag = false;
      break;
    }
  }
  if (!flag) {
    cout << "-1\n";
    return 0;
  }
  vector<int> sz(n + 1), ans;
  function<void(int, int)> Dfs = [&](int v, int p) {
    sz[v] = 1;
    for (auto to: g[v]) {
      if (to == p) continue;
      Dfs(to, v);
      int i = ind[v][to];
      if (sz[to] & 1) {
        ans.emplace_back(i);
        sz[v] += sz[to];
      }
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!sz[i]) {
      Dfs(i, -1);
    }
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}
