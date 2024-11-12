/**
 *    author:  feev1x
 *    created: 11.11.2024 20:00:37
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::set<std::pair<int, int>> bs;
  auto Report = [&]() {
    if (bs.size() >= (m + 1) / 2) {
      printf("! Yes\n");
      fflush(stdout);
      for (auto [u, v]: bs) {
        printf("%d %d\n", u, v);
        fflush(stdout);
      }
    } else {
      printf("! No\n");
      fflush(stdout);
    }
  };
  auto Ask = [&](int u) {
    printf("? %d\n", u);
    fflush(stdout);
    int v; scanf("%d", &v);
    return v;
  };
  if (m >= 2 * n) {
    Report();
    return 0;
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int v = 1; v <= n; ++v) {
    while (true) {
      int got = Ask(v);
      if (got == -1) {
        break;
      }
      g[v].emplace_back(got);
      g[got].emplace_back(v);
    }
  }
  auto Add = [&](int u, int v) {
    if (u > v) {
      std::swap(u, v);
    }
    bs.emplace(u, v);
  };
  std::vector<bool> used(n + 1);
  std::vector<int> fup(n + 1), tin(n + 1);
  int tm = 0;
  std::function<void(int, int)> Dfs = [&](int v, int p) {
    used[v] = true;
    tin[v] = ++tm;
    fup[v] = tin[v];
    bool flag = false;
    for (auto to: g[v]) {
      if (to == p && !flag) {
        flag = true;
        continue;
      }
      if (used[to]) {
        fup[v] = std::min(fup[v], tin[to]);
      } else {
        Dfs(to, v);
        fup[v] = std::min(fup[v], fup[to]);
        if (tin[v] < fup[to]) {
          Add(v, to);
        }
      }
    }
  };
  for (int v = 1; v <= n; ++v) {
    if (!used[v]) {
      Dfs(v, 0);
    }
  }
  Report();
  return 0;
}
