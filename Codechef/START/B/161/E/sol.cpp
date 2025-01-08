/**
 *    author:  feev1x
 *    created: 20.11.2024 22:12:00
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    if (n <= 2) {
      printf("%d\n", n);
      continue;
    }
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    std::vector<int> cnt(n + 1, 1), dep(n + 1), par(n + 1);
    std::vector<bool> is(n + 1);
    is[n] = true;
    std::function<bool(int, int)> Dfs = [&](int v, int p) {
      dep[v] = dep[p] + 1;
      par[v] = p;
      for (auto to: g[v]) {
        if (to == p) {
          continue;
        }
        if (Dfs(to, v)) {
          is[v] = true;
        }
        cnt[v] += cnt[to];
      }
      return is[v];
    };
    Dfs(1, 0);
    par[1] = -1;
    int res = dep[n];
    int v = par[n];
    std::vector<int> vec;
    while (v != -1) {
      for (auto to: g[v]) {
        if (is[to]) {
          continue;
        }
        vec.emplace_back(cnt[to]); 
      }
      v = par[v];
    }
    std::sort(vec.begin(), vec.end());
    int sz = ((int)vec.size() + 1) - k;
    for (int i = 0; i < sz; ++i) {
      res += vec[i];
    }
    printf("%d\n", res);
  }
  return 0;
}
