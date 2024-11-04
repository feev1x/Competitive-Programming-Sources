/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int sz[N], p[N], g[N];

int get(int v) {
  return v == p[v] ? v : p[v] = get(p[v]);
}

void union_(int u, int v) {
  u = get(u);
  v = get(v);
  if (u != v) {
    if (sz[u] > sz[v]) swap(u, v);
    p[u] = v;
    sz[v] += sz[u];
    g[v] = max(g[v], g[u]);
  }
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= N; ++i) {
    g[i] = -1;
    sz[i] = 1;
    p[i] = i;
  }
  int n; cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    if (b[i] == 0) {
      g[i] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int u = b[i];
    if (u > 0) {
      union_(u, i);
    }
  }
  int mx = 0, gen = -1;
  for (int i = 1; i <= n; ++i) {
    int u = get(i);
    if (sz[u] > mx) {
      mx = sz[u];
      gen = g[u];
    }
  }
  cout << gen << ' ' << mx << '\n';
}

