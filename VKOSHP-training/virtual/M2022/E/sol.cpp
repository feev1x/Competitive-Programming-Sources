/**
 *    author:  feev1x
 *    created: 18.10.2024 10:32:00
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int x = 0;
  vector<int> a(n + 1), xr(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    x ^= a[i];
    xr[i] = a[i];
  }
  if (x) {
    cout << -1 << '\n';
    return 0;
  }
  int cnt = 1;
  function<void(int, int)> Dfs = [&](int v, int p) {
    for (auto to: g[v]) {
      if (to == p) continue;
      Dfs(to, v);
      if (!xr[to]) {
        cnt++;
      }
      xr[v] ^= xr[to];
    }
  };
  Dfs(1, -1);
  cout << cnt << '\n';
  return 0;
}
