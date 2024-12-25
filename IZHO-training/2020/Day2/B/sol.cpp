/**
 *    author:  feev1x
 *    created: 24.12.2024 12:59:45
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

inline void min_self(i64 &a, i64 b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  auto Bfs = [&](int start) {
    std::queue<int> q;
    std::vector<i64> dis(n + 1, INF);
    dis[start] = 0;
    q.emplace(start);
    while (q.size()) {
      auto u = q.front();
      q.pop();
      for (auto to: g[u]) {
        if (dis[to] > dis[u] + 1) {
          dis[to] = dis[u] + 1;
          q.emplace(to);
        }
      }
    }
    return dis;
  };
  std::vector<std::vector<i64>> dis(n + 1);
  for (int i = 1; i <= n; ++i) {
    dis[i] = Bfs(i);
  }
  int id = 1;
  std::vector<std::pair<int, i64>> vir(1);
  while (q--) {
    int type; std::cin >> type;
    if (type == 1) {
      int v, t; std::cin >> v >> t;
      vir.emplace_back(v, t);
      continue;
    }
    int l, r, t; std::cin >> l >> r >> t;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      bool flag = true;
      for (int j = l; j <= r; ++j) {
        if (dis[vir[j].first][i] + vir[j].second > t) {
          flag = false;
          break;
        }
      }
      cnt += flag;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
