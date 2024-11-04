/**
 *    author:  feev1x
 *    created: 21.10.2024 09:55:41
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<vector<pair<int, int64_t>>> g(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; int64_t p, q; cin >> u >> v >> p >> q;
    g[u].emplace_back(v, p);
    g[v].emplace_back(u, q);
  }
  vector<bool> cn(n + 1);
  vector<int64_t> cost(n + 1), costd(n + 1);
  int par = -1;
  int64_t ds = 0;
  function<bool(int, int)> Find = [&](int v, int p) {
    if (cn[v] = (v == n)) {
      par = p;
      return true;
    }
    for (auto [to, w]: g[v]) {
      if (to == p) continue;
      if (cn[v] = Find(to, v)) {
        return true;
      }
    }
    return false;
  };
  Find(1, -1);
  function<int64_t(int, int, int64_t)> Dfs = [&](int v, int p, int64_t cost) {
    if (cn[v]) {
      int64_t res = 0;
      for (auto [to, w]: g[v]) {
        if (cn[to] || to == p) continue;
        int64_t sm = Dfs(to, v, w);
        if (sm > 0) {
          res += sm;
        }
      }
      for (auto [to, w]: g[v]) {
        if (!cn[to] || to == p) continue;
        res += Dfs(to, v, w);
        res += w;
      }
      return res;
    } else {
      int64_t res = cost;
      for (auto [to, w]: g[v]) {
        if (to == p) {
          res += w;
          break;
        }
      }
      for (auto [to, w]: g[v]) {
        if (to == p) continue;
        int64_t sm = Dfs(to, v, w);
        if (sm > 0) {
          res += sm;
        }
      }
      return res;
    }
  };
  cout << Dfs(1, -1, 0) << '\n';
  return 0;
}

