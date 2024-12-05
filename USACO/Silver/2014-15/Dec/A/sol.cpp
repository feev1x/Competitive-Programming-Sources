/**
 *    author:  feev1x
 *    created: 23.11.2024 13:16:20
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::freopen("piggyback.in", "r", stdin);
  std::freopen("piggyback.out", "w", stdout);
  int b, e, p, n, m; scanf("%d%d%d%d%d", &b, &e, &p, &n, &m);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  auto Dijkstra = [&](int start, int cost) {
    std::vector<int> dis(n + 1, INF);
    std::set<std::pair<int, int>> st;
    dis[start] = 0;
    st.emplace(0, start);
    while (st.size()) {
      int v = st.begin()->second;
      st.erase(st.begin());
      for (auto to: g[v]) {
        if (dis[to] > dis[v] + cost) {
          st.erase({dis[to], to});
          dis[to] = dis[v] + cost;
          st.emplace(dis[to], to);
        }
      }
    }
    return dis;
  };
  auto dis1 = Dijkstra(1, b);
  auto dis2 = Dijkstra(2, e);
  auto dis3 = Dijkstra(n, p);
  int res = INF;
  for (int v = 1; v <= n; ++v) {
    res = std::min(res, dis1[v] + dis2[v] + dis3[v]);
  }
  printf("%d\n", res);
  return 0;
}
