/**
 *    author:  feev1x
 *    created: 02.11.2024 19:13:40
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
  int n; scanf("%d", &n);  
  vector<vector<int>> g(n + 1);
  vector<int> d(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    d[u]++, d[v]++;
  }
  vector<ll> ans(n + 1), cnt(n + 1);
  function<void(int, int)> Dfs = [&](int v, int p) {
    if (d[p] == 3 && d[v] == 2) {
      cnt[v]++;
    }
    for (auto to: g[v]) {
      if (to == p) continue;
      Dfs(to, v);
      if (d[v] == 3) ans[v] += cnt[v] * cnt[to], cnt[v] += cnt[to];
      if (d[v] == 2 && d[to] == 3) ans[v] += cnt[to];
      ans[v] += ans[to];
    }
  };
  Dfs(1, -1);
  for (int v = 1; v <= n; ++v) {
    debug(ans[v], cnt[v], v);
  }
  printf("%lld\n", ans[1]);
  return 0;
}
