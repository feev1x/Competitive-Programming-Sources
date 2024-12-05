/**
 *    author:  feev1x
 *    created: 29.11.2024 20:46:15
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9 + 1e8 + 4e7;

int main() {
  std::freopen("buffet.in", "r", stdin);
  std::freopen("buffet.out", "w", stdout);
  int n, e; scanf("%d%d", &n, &e);
  std::vector<std::pair<int, std::vector<int>>> g(n + 1);
  std::vector<std::pair<int, std::vector<int>>> old_g(n + 1);
  for (int i = 1; i <= n; ++i) {
    int d; scanf("%d%d", &g[i].first, &d);
    g[i].second.resize(d);
    for (auto &u: g[i].second) {
      scanf("%d", &u);
    }
  }
  std::vector<int> sr(n + 1);
  std::iota(sr.begin(), sr.end(), 0);
  std::sort(sr.begin() + 1, sr.end(), [&](int i, int j) {
      return g[i].first < g[j].first;
      });
  std::vector dis(n + 1, std::vector(n + 1, INF));
  std::queue<std::pair<int, int>> qq;
  for (int i = 1; i <= n; ++i) {
    dis[i][i] = 0;
    qq.emplace(i, i);
  }
  while (qq.size()) {
    auto [i, v] = qq.front();
    qq.pop();
    for (auto to: g[v].second) {
      if (dis[i][to] > dis[i][v] + e) {
        dis[i][to] = dis[i][v] + e;
        qq.emplace(i, to);
      }
    }
  }
  std::vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = g[sr[i]].first;
    for (int j = 1; j < i; ++j) {
      if (dis[sr[i]][sr[j]] == INF) {
        continue;
      }
      dp[i] = std::max(dp[i], g[sr[i]].first + dp[j] - dis[sr[j]][sr[i]]);
    }
  }
  printf("%d\n", *std::max_element(dp.begin(), dp.end()));
  return 0;
}
