/**
 *    author:  feev1x
 *    created: 22.10.2024 17:56:02
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
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto Modp = [&](int64_t a, int64_t b) {
    return (a + b) % mod;
  };
  auto Modm = [&](int64_t a, int64_t b) {
    return (a * b) % mod;
  };
  int n, m; cin >> n >> m;
  int s, t; cin >> s >> t;
  int64_t l; cin >> l;
  vector<vector<pair<int, int64_t>>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    int64_t w; cin >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  auto Dijkstra = [&](int start) {
    vector<int64_t> dis(n + 1, inf), cnt(n + 1);
    dis[start] = 0;
    cnt[start] = 1;
    set<pair<int64_t, int>> q;
    q.emplace(0, start);
    while (!q.empty()) {
      int v = q.begin()->second;
      q.erase(q.begin());
      if (dis[v] >= l) break;
      for (auto [to, w]: g[v]) {
        if (dis[to] == dis[v] + w) {
          cnt[to] = Modp(cnt[to], cnt[v]);
        } else if (dis[to] > dis[v] + w) {
          q.erase({dis[to], to});
          dis[to] = dis[v] + w;
          q.emplace(dis[to], to);
          cnt[to] = cnt[v];
        }
      }
    }
    return pair{dis, cnt};
  };
  auto [diss, cnts] = Dijkstra(s);
  auto [dist, cntt] = Dijkstra(t);
  int64_t opt = diss[t], res = 0;
  for (int v = 1; v <= n; ++v) {
    if (v == t) continue;
    if (diss[v] + dist[v] > opt) {
      continue;
    }
    for (auto [to, w]: g[v]) {
      if (w + diss[v] + dist[to] == l) {
        res = Modp(res, Modm(cnts[v], cntt[to]));
      }
    }
  }
  if (l == opt) res = cnts[t];
  cout << res << '\n';
  return 0;
}
