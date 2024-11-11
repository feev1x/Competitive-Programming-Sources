/**
 *    author:  feev1x
 *    created: 10.11.2024 20:17:45
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
  std::vector a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  std::vector dp(n, std::vector<int>(1 << n, 2e9));
  std::vector p(n, std::vector<int>(1 << n, -1));
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    q.emplace(i, 1 << i);
    dp[i][1 << i] = 0;
  }
  while (!q.empty()) {
    auto [cur, mask] = q.front();
    q.pop();
    for (int i = 0; i < n; ++i) {
      if (mask & 1 << i) {
        continue;
      }
      if (dp[i][mask | 1 << i] > dp[cur][mask] + a[cur][i]) {
        dp[i][mask | 1 << i] = dp[cur][mask] + a[cur][i];
        p[i][mask | 1 << i] = cur;
        q.emplace(i, mask | 1 << i);
      }
    }
  }
  int res = 2e9, ls = -1;
  for (int i = 0; i < n; ++i) {
    if (res > dp[i][(1 << n) - 1]) {
      res = dp[i][(1 << n) - 1];
      ls = i;
    }
  }
  assert(ls != -1);
  printf("%d\n", res);
  std::vector<int> path;
  int temp;
  for (int v = ls, mask = (1 << n) - 1; v != -1; temp = v, v = p[v][mask], mask ^= 1 << temp) {
    path.emplace_back(v + 1);
  }
  std::reverse(path.begin(), path.end());
  for (auto u: path) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
