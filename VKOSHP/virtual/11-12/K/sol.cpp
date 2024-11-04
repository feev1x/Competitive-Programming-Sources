/**
 *    author:  feev1x
 *    created: 16.10.2024 11:41:57
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
//  freopen("tree.in", "r", stdin);
//  freopen("tree.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> p(n + 1), d(n + 1), tin(n + 1), tout(n + 1);
  vector<vector<int>> g(n + 1), dt;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    if (p[i] == -1) p[i] = 0;
    g[p[i]].emplace_back(i);
  }
  d[0] = -1;
  int tm = 0;
  function<void(int)> dfs = [&](int v) {
    tin[v] = tm++;
    d[v] = d[p[v]] + 1;
    if (dt.size() <= d[v]) dt.resize(d[v] + 1);
    dt[d[v]].emplace_back(tin[v]);
    mx = max(mx, d[v]);
    for (auto to: g[v]) {
      dfs(to);
    }
    tout[v] = tm++;
  };
  dfs(1);
  int m; cin >> m;
  while (m--) {
    int v, k; cin >> v >> k;
    if (d[v] + k > mx) {
      cout << 0 << '\n';
    } else {
      int dep = d[v] + k;
      if (dt[dep].empty()) {
        cout << 0 << '\n';
        continue;
      }
      int l = --upper_bound(dt[dep].begin(), dt[dep].end(), tin[v]) - dt[dep].begin();
      int r = --upper_bound(dt[dep].begin(), dt[dep].end(), tout[v]) - dt[dep].begin();
      cout << r - l << '\n';
    }
  }
}
