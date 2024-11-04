/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int p[N], d[N];
vector<vector<int>> g(N);

void dfs(int v) {
  d[v] = d[p[v]] + 1;
  for (auto to: g[v]) {
    if (to == p[v]) continue;
    p[to] = v;
    dfs(to);
  }
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); 
  d[0] = -1;
  p[1] = 0;
  int n, q; cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1);
  while (q--) {
    int 
  }
}

