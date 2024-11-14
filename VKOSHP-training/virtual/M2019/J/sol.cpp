/**
 *    author:  feev1x
 *    created: 12.11.2024 13:14:05
**/
#include "bits/stdc++.h"

using i64 = long long;
using u64 = unsigned i64;
using i128 = __int128_t;
using u128 = __uint128_t;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> cat(n + 1), jury(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      cat[v].emplace_back(u);
      jury[u].emplace_back(v);
    }
    std::vector<int> cats, jurys;
    std::vector<bool> used_cat(n + 1), used_jury(n + 1);
    std::function<void(int)> Dfs_Cat = [&](int v) {
      used_cat[v] = true;
      for (auto to: cat[v]) {
        if (used_cat[to]) continue;
        Dfs_Cat(to);
      }
      cats.emplace_back(v);
    };
    std::function<void(int)> Dfs_Jury = [&](int v) {
      used_jury[v] = true;
      for (auto to: jury[v]) {
        if (used_jury[to]) continue;
        Dfs_Jury(to);
      }
      jurys.emplace_back(v);
    };
    Dfs_Cat(1);
    Dfs_Jury(1);
    if (cats.size() == n && jurys.size() == n) {
      printf("No\n");
      continue;
    }
    std::vector<bool> used(n + 1);
    printf("Yes\n");
    if (jurys.size() == n) {
      printf("%d %d\n", n - (int)cats.size(), (int)cats.size());
      for (auto u: cats) {
        used[u] = true;
      }
      for (int u = 1; u <= n; ++u) {
        if (!used[u]) {
          printf("%d ", u);
        }
      }
      printf("\n");
      for (auto u: cats) {
        printf("%d ", u);
      }
      printf("\n");
      continue;
    }
    printf("%d %d\n", (int)jurys.size(), n - (int)jurys.size());
    for (auto u: jurys) {
      printf("%d ", u);
      used[u] = true;
    }
    printf("\n");
    for (int u = 1; u <= n; ++u) {
      if (!used[u]) {
        printf("%d ", u);
      }
    }
    printf("\n");
  }
  return 0;
}
