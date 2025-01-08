/**
 *    author:  feev1x
 *    created: 04.11.2024 19:19:29
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

const int mod = 998244353;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

signed main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  vector<vector<int>> gr(n + 1), rg(n + 1);
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    gr[i].emplace_back(i + 1);
    rg[i + 1].emplace_back(i);
  }
  gr[n].emplace_back(1);
  rg[1].emplace_back(n);
  for (int i = 1; i <= m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    gr[u].emplace_back(v);
    rg[v].emplace_back(u);
  }
  vector<bool> used(n + 1);
  auto Dfs = [&](int u) {
    int v = -1;
    while (rg[gr[u][0]].size() == 1 && gr[gr[u][0]].size() == 1) {
      if (used[u]) {
        return;
      }
      used[u] = true;
      u = gr[u][0];
    }
    v = gr[u][0];
    int cnt = 1;
    while (rg[u].size() == 1 && gr[u].size() == 1) {
      cnt++;
      used[u] = true;
      u = rg[u][0];
    }
    g[u].emplace_back(v, cnt);
  };
  for (int v = 1; v <= n; ++v) {
    if (!used[v] && rg[v].size() == 1 && gr[v].size() == 1) Dfs(v);
  }
  for (int v = 1; v <= n; ++v) {
    for (auto to: gr[v]) {
      if (!used[to]) {
        g[v].emplace_back(to, 1);
      }
    }
  }
  vector<int> use, val(n + 1);
  for (int v = 1; v <= n; ++v) {
    if (!used[v]) {
      use.emplace_back(v);
      val[v] = use.size() - 1;
    }
  }
  int len = int(use.size());
  vector dp(len, vector<int>(k + 1));
  int v = 1, cnt = 0;
  while (rg[v].size() == 1 && gr[v].size() == 1) {
    if (cnt >= k) break;
    v = gr[v][0];
    cnt++;
  }
  if (cnt >= k) {
    printf("1\n");
    return 0;
  }
  dp[val[v]][cnt] = 1;
  for (int j = cnt; j < k; ++j) {
    for (int i = 0; i < len; ++i) {
      if (!dp[i][j]) continue;
      for (auto [to, w]: g[use[i]]) {
        assert(!used[to]);
        if (j + w <= k) {
          add_self(dp[val[to]][j + w], dp[i][j]);
        } else {
          add_self(dp[val[to]][k], dp[i][j]);
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < len; ++i) {
    add_self(res, dp[i][k]);
  }
  printf("%d\n", res);
  return 0;
}
