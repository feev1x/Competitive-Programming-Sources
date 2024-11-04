/**
 *    author:  feev1x
 *    created: 19.10.2024 18:36:42
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
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1);
  int en = -1;
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
  }
  vector<int> p(n + 1), dis(n + 1);
  dis[1] = 0;
  vector<bool> used(n + 1);
  queue<int> q;
  q.emplace(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    used[cur] = true;
    for (auto to: g[cur]) {
      if (to == 1 && cur != 1) {
        en = cur;
        break;
      }
      if (!used[to]) {
        dis[to] = dis[cur] + 1;
        p[to] = cur;
        q.emplace(to);
        used[to] = true;
      }
    }
    if (en != -1) break;
  }
  if (en == -1) {
    cout << -1 << '\n';
    return 0;
  }
  debug(en);
  cout << dis[en] + 1 << '\n';
  return 0;
}
