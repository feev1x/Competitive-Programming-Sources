/**
 *    author:  feev1x
 *    created: 08.11.2024 12:13:42
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
  int n, m; scanf("%d%d", &n, &m);  
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<bool> used(n + 1);
  int c = 0;
  vector<int> a, val(n + 1);
  vector<pair<int, int>> e;
  map<int, map<int, bool>> dont;
  function<void(int, int)> Dfs = [&](int v, int p) {
    used[v] = true;
    for (auto to: g[v]) {
      if (to == p || dont[to][v]) continue;
      debug(to, v);
      if (used[to]) {
        c++;
        a.emplace_back(v);
        e.emplace_back(c, val[to]);
        dont[v][to] = dont[to][v] = true;
        val[v] = c;
      } else {
        if (val[v] == 0) {
          c++;
          val[v] = c;
          a.emplace_back(v);
        }
        if (val[to] == 0) {
          c++;
          val[to] = c;
          a.emplace_back(to);
        }
        e.emplace_back(val[v], val[to]);
        Dfs(to, v);
      }
    }
  };
  Dfs(1, -1);
  printf("%d\n", c);
  for (auto u: a) {
    printf("%d ", u);
  }
  printf("\n");
  for (auto [u, v]: e) {
    printf("%d %d\n", u, v);
  }
  return 0;
}
