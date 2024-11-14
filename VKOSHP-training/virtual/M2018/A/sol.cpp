/**
 *    author:  feev1x
 *    created: 11.11.2024 11:59:59
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  int n; scanf("%d", &n);
  std::set<int> g[n + 1]{};
  std::multiset<int> mxd;
  std::set<std::pair<int, int>> leaf;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace(v);
    g[v].emplace(u);
  }
  for (int i = 1; i <= n; ++i) {
    mxd.emplace(g[i].size());
    if (g[i].size() == 1) {
      leaf.emplace(g[*g[i].begin()].size(), i);
    }
  }
  int mx = *--mxd.end();
  bool billy = true;
  if (mx > 2) {
    int cnt = n - mx - 1;
    cnt -= (mx - 1);
    if (cnt % 2 == 0) billy = false;
  }
  printf(billy ? "Billy\n" : "Ricardo\n");
  return 0;
}
