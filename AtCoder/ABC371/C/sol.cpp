/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int m; cin >> m;
  vector<vector<int>> g(n + 1), a(n + 1, vector<int>(n + 1));
  int mm = m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  cin >> m;
  int M = m;
  map<int, map<int, bool>> mp;
  while (m--) {
    int u, v; cin >> u >> v;
    mp[u][v] = true;
    mp[v][u] = true;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  int res = 1e9;
  do {
    int cost = 0;
    map<int, map<int, bool>> mp1;
    for (int u = 1; u <= n; ++u) {
      for (auto v: g[u]) {
        if (!mp[p[u - 1]][p[v - 1]]) {
          cost += a[min(p[u - 1], p[v - 1])][max(p[u - 1], p[v - 1])];
        } else {
          mp1[p[u - 1]][p[v - 1]] = mp1[p[v - 1]][p[u - 1]] = 1;
        }
      }
    }
    for (auto [u, mmp]: mp) {
      for (auto [v, ch]: mmp) {
        if (!ch) continue;
        if (!mp1[u][v]) {
          cost += a[min(u, v)][max(u, v)];
        }
      }
    }
    res = min(res, cost / 2);
  } while (next_permutation(p.begin(), p.end()));
  cout << res << '\n';
}

