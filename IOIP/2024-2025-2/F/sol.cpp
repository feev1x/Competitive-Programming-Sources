/**
 *    author:  feev1x
 *    created: 06.12.2024 18:43:57
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<int> val(n + 1), cols;
  std::vector<bool> col(n + 1), dont(n + 1);
  std::iota(val.begin(), val.end(), 0);
  for (int _ = 0;  _ < 3; ++_) {
    int k, u; scanf("%d%d", &k, &u);
    cols.emplace_back(u);
    for (int i = 1; i < k; ++i) {
      int v; scanf("%d", &v);
      dont[v] = true;
      val[v] = u;
    }
  }
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    u = val[u];
    v = val[v];
    if (u == v) {
      continue;
    }
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<std::vector<int>> dis(3, std::vector<int>(n + 1, INF));
  std::vector<std::vector<int>> p(3, std::vector<int>(n + 1, INF));
  for (int j = 0; j < 3; ++j) {
    int u = cols[j];
    std::queue<int> q;
    dis[j][u] = 0;
    q.emplace(u);
    while (q.size()) {
      int v = q.front();
      q.pop();
      for (auto to: g[v]) {
        if (dis[j][to] > dis[j][v] + 1) {
          dis[j][to] = dis[j][v] + 1;
          p[j][to] = v;
          q.emplace(to);
        }
      }
    }
  }
  int res = INF, opt = -1;
  for (int v = 1; v <= n; ++v) {
    if (dont[v]) {
      continue;
    }
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
      sum += dis[i][v];
    }
    if (sum - 2 < res) {
      res = sum - 2;
      opt = v;
    }
  }
  printf("%d\n", res);
  std::set<int> st;
  for (int i = 0; i < 3; ++i) {
    for (int v = opt; v != INF; v = p[i][v]) {
      st.emplace(v);
    }
  }
  for (auto u: cols) {
    st.erase(u);
  }
  for (auto u: st) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
