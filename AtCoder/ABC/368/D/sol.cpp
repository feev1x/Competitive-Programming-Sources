/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 5;
int sz[N], p[N];

int get(int n) {
  return p[n] == n ? n : p[n] = get(p[n]);
}

void union_(int u, int v) {
  u = get(u);
  v = get(v);
  if (u != v) {
    if (sz[u] > sz[v]) swap(u, v);
    p[u] = v;
    sz[v] += sz[u];
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= N; ++i) {
    sz[i] = 1;
    p[i] = i;
  }
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int rnd = -1;
  map<int, bool> in;
  for (int i = 0; i < k; ++i) {
    int v; cin >> v;
    in[v] = true;
    if (rnd == -1) 
    rnd = v;
  }
  function<bool(int, int)> dfs = [&](int v, int p) {
    bool nw = in[v];
    for (auto u: g[v]) {
      if (u == p) continue;
      if (dfs(u, v)) {
        nw = true;
        union_(u, v);
      }
    }
    return nw;
  };
  dfs(rnd, -1);
  cout << sz[get(rnd)] << '\n';
}


