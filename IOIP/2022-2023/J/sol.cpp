/**
 *    author:  feev1x
 *    created: 06.11.2024 12:51:33
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int n, m, k, t; scanf("%d%d%d%d", &n, &m, &k, &t);
  vector<vector<int>> g(n + 1);
  vector<int> Q(t), dr(n + 1), p(k);
  for (auto &u: p) {
    scanf("%d", &u);
  }
  for (auto &u: Q) {
    scanf("%d", &u);
    dr[u] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  auto Bfs = [&](int start) {
    vector<int> dis(n + 1, 1e9);
    dis[start] = 0;
    int mn = 1e9;
    queue<int> q;
    q.emplace(start);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (dr[cur]) {
        mn = min(mn, dis[cur]);
      }
      for (auto to: g[cur]) {
        if (dis[to] > dis[cur] + 1) {
          dis[to] = dis[cur] + 1;
          q.emplace(to);
        }
      }
    }
    return pair{mn, dis};
  };
  vector<pair<int, vector<int>>> ps;
  int res = 1e9;
  for (int i = 0; i < k; ++i) {
    auto sm = Bfs(p[i]);
    res = max(res, sm.first);
    ps.emplace_back(sm);
  }
  assert(ps.size() == k);
  int x = -1;
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 0; j < k; ++j) {
      ans = max(ans, min(ps[j].first, ps[j].second[i]));
    }
    if (res > ans) {
      res = ans;
      x = i;
    }
  }
  assert(x != -1);
  printf("%d %d\n", x, res);
  return 0;
}
