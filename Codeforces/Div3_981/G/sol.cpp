/**
 *    author:  feev1x
 *    created: 24.10.2024 20:37:09
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<vector<int>> anc(19, vector<int>(n + 1));
    function<void(int, int)> Dfs = [&](int v, int p) {

    };
  }
  return 0;
}
