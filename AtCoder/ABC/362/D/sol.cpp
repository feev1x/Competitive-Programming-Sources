/**
 *    author:  feev1x
 *    created: 17.10.2024 20:58:17
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int64_t inf = 1e18;

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int64_t> a(n + 1);
  vector<vector<pair<int, int64_t>>> g(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    int64_t w; cin >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  auto Dijkstra = [&](int st) {
    vector<int64_t> dis(n + 1, inf);
    dis[st] = 0;
    set<pair<int64_t, int>> q;
    q.emplace(dis[st], st);
    while (!q.empty()) {
      int cur = q.begin()->second;
      q.erase(q.begin());
      for (auto [to, w]: g[cur]) {
        if (dis[to] > dis[cur] + w + a[to]) {
          q.erase({dis[to], to});
          dis[to] = dis[cur] + w + a[to];
          q.emplace(dis[to], to);
        }
      }
    }
    return dis;
  };
  auto dis = Dijkstra(1);
  for (int i = 2; i <= n; ++i) {
    cout << dis[i] + a[1] << " \n"[i == n];
  }
  return 0;
}
