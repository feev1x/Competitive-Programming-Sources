/**
 *    author:  feev1x
 *    created: 10.11.2024 23:05:07
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

const int mod = 998244353;

ld binpow(ld a, int n) {
  ld res = 1;
  while (n) {
    if (n & 1) {
      res = fmod(res * a, mod);
    }
    a = fmod(a * a, mod);
    n >>= 1;
  }
  return res;
}

ll divi(ld a, ld b) {
  return fmod(a * binpow(b, mod - 2), mod);
}

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    std::vector<int> mn(n + 1, n), deg(n + 1);
    std::function<void(int, int)> Dfs = [&](int v, int p) {
      deg[v] = deg[p] + 1;
      if (g[v].size() == 1) {
        mn[v] = deg[v];
      }
      for (auto to: g[v]) {
        if (to == p) continue;
        Dfs(to, v);
        mn[v] = std::min(mn[v], mn[to]);
      }
    };
    Dfs(1, 0);
    for (int v = 1; v <= n; ++v) {
      printf("%lld ", divi(mn[v] - deg[v], mn[v] - 1));
    }
    printf("\n");
  }
  return 0;
}
