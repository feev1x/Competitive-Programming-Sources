/**
 *    author:  feev1x
 *    created: 14.10.2024 14:11:00
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<vector<int>> in(n + 1), out(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    in[v].emplace_back(u);
    out[u].emplace_back(v);
  }
  vector<int> len(n + 1, 1), ilen(n + 1, 1);
  vector<bool> used(n + 1);
  function<void(int)> dfs = [&](int v) {
    used[v] = true;
    for (auto to: out[v]) {
      if (!used[to]) {
        dfs(to);
      }
      len[v] = max(len[v], len[to] + 1);
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) dfs(i);
  }
  for (int i = 1; i <= n; ++i) {
    used[i] = false;
  }
  dfs = [&](int v) {
    used[v] = true;
    for (auto to: in[v]) {
      if (!used[to]) {
        dfs(to);
      }
      ilen[v] = max(ilen[v], ilen[to] + 1);
    }
  };
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) dfs(i);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, len[i] + ilen[i] - 2);
  }
  cout << res << '\n';
}
