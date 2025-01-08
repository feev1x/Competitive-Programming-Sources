/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<tuple<int, int64_t, bool>>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    int64_t w; cin >> w;
    g[u].emplace_back(v, w, 1);
    g[v].emplace_back(u, w, 0);
  }
  vector<int64_t> x(n + 1, -1e18);
  function<void(int, int, int, bool)> dfs = [&](int v, int p, int we, bool vl) {
    if (p == -1) {
      x[v] = 1e15;
    } else {
      x[v] = x[p] + (!vl ? -we : we);
    }
    for (auto [to, w, Vl]: g[v]) {
      if (x[to] != -1e18) continue;
      dfs(to, v, w, Vl);
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (x[i] == -1e18) dfs(i, -1, 1, 1);
  }
  for (int i = 1; i <= n; ++i) {
    cout << x[i] << ' ';
  }
  cout << '\n';
}

