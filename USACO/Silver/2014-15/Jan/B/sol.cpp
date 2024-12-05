/**
 *    author:  feev1x
 *    created: 27.11.2024 17:13:23
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e3 + 10;
constexpr i64 INF = 1e18;

inline void min_self(std::pair<i64, int> &a, std::pair<i64, int> b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::freopen("cowroute.in", "r", stdin);
  std::freopen("cowroute.out", "w", stdout);
  int a, b, n; scanf("%d%d%d", &a, &b, &n);
  std::vector g(MXSZ, std::vector<std::pair<i64, int>>(MXSZ, {INF, INF}));
  for (int i = 0; i < MXSZ; ++i) {
    g[i][i] = {0, 0};
  }
  for (int i = 0; i < n; ++i) {
    i64 cost; int m; scanf("%lld%d", &cost, &m);
    std::vector<int> v(m);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &v[j]);
      for (int k = 0; k < j; ++k) {
        min_self(g[v[k]][v[j]], {cost, j - k});
      }
    }
  }
  std::vector dis(MXSZ, std::pair{INF, (int)1e9});
  std::vector<bool> used(MXSZ);
  dis[a] = {0, 0};
  for (int _ = 0; _ < MXSZ; ++_) {
    int v = -1;
    for (int i = 1; i < MXSZ; ++i) {
      if (used[i]) {
        continue;
      }
      if (v == -1 || dis[v] > dis[i]) {
        v = i;
      }
    }
    if (v == -1) {
      break;
    }
    used[v] = true; 
    for (int to = 1; to < MXSZ; ++to) {
      auto pr = dis[v];
      pr.first += g[v][to].first;
      pr.second += g[v][to].second;
      min_self(dis[to], pr);
    }
  }
  if (dis[b].first == INF) {
    printf("-1 -1\n");
  } else {
    printf("%lld %d\n", dis[b].first, dis[b].second);
  }
  return 0;
}
