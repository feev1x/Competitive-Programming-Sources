/**
 *    author:  feev1x
 *    created: 27.11.2024 17:43:13
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 10001, N = 101;


int main() {
  std::freopen("meeting.in", "r", stdin);
  std::freopen("meeting.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> g[2][N]{};
  for (int i = 0; i < m; ++i) {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    g[0][a].emplace_back(b, c);
    g[1][a].emplace_back(b, d);
  }
  bool dis[2][N][MXSZ]{};
  dis[0][1][0] = dis[1][1][0] = true;
  std::function<void(bool, int, int)> Dfs = [&](bool type, int v, int ds) {
    for (auto [to, w]: g[type][v]) {
      if (!dis[type][to][ds + w]) {
        dis[type][to][ds + w] = true;
        Dfs(type, to, ds + w);
      }
    }
  };
  Dfs(0, 1, 0);
  Dfs(1, 1, 0);
  for (int i = 0; i < MXSZ; ++i) {
    if (dis[0][n][i] & dis[1][n][i]) {
      printf("%d\n", i);
      exit(0);
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}
