/**
 *    author:  feev1x
 *    created: 04.01.2025 09:20:05
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  if (n == 1) {
    std::cout << "-1\n";
    exit(0);
  }
  std::vector w(n + 1, std::vector<int>(n + 1));
  std::vector edge(n + 1, std::vector<bool>(n + 1, true));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> w[i][j];
    }
  }
  if (k == 2) {
    for (int _ = 0; _ < n * n; ++_) {
      int i, j; std::cin >> i >> j;
      edge[i][j] = false;
      int res = INF;
      for (int v = 1; v <= n; ++v) {
        if (edge[1][v] && edge[v][n]) {
          res = std::min(res, w[1][v] + w[v][n]);
        }
      }
      if (res == INF) res = -1;
      std::cout << res << '\n';
    }
  } else if (k == 3) {
    std::multiset<int> st;
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        st.emplace(w[1][u] + w[u][v] + w[v][n]);
      }
    }
    for (int _ = 0; _ < n * n; ++_) {
      int u, v; std::cin >> u >> v;
      auto it = st.find(w[1][u] + w[u][v] + w[v][n]);
      if (it != st.end() && edge[1][u] && edge[u][v] && edge[v][n]) {
        st.erase(it);
      }
      if (u == 1) {
        for (int i = 1; i <= n; ++i) {
          if (u == v && i == v) {
            continue;
          }
          it = st.find(w[1][v] + w[v][i] + w[i][n]);
          if (it != st.end() && edge[1][v] && edge[v][i] && edge[i][n]) {
            st.erase(it);
          }
        }
      }
      if (v == n) {
        for (int i = 1; i <= n; ++i) {
          if (i == u && u == v) {
            continue;
          }
          it = st.find(w[1][i] + w[i][u] + w[u][n]);
          if (it != st.end() && edge[1][i] && edge[i][u] && edge[u][n]) {
            st.erase(it);
          }
        }
      }
      edge[u][v] = false;
      if (st.size()) {
        std::cout << *st.begin() << '\n';
      } else {
        std::cout << "-1\n";
      }
    }
  } else if (k == 4) {
    std::stack<std::pair<int, int>> query;
    for (int i = 0; i < n * n; ++i) {
      int u, v; std::cin >> u >> v;
      edge[u][v] = false;
      query.emplace(u, v);
    }
    std::stack<int> ans;
    int min = INF;
    std::vector<std::vector<int>> g(n + 1);
    while (query.size()) {
      auto [u, v] = query.top();
      query.pop();
      ans.emplace(min == INF ? -1 : min);
      edge[u][v] = true;
      g[u].emplace_back(v);
      if (edge[1][u]) {
        for (auto i: g[v]) {
          if (edge[i][n]) {
            min = std::min(min, w[1][u] + w[u][v] + w[v][i] + w[i][n]);
          }
        }
      }
      if (edge[v][n]) {
        for (auto i: g[1]) {
          if (edge[i][u]) {
            min = std::min(min, w[1][i] + w[i][u] + w[u][v] + w[v][n]);
          }
        }
      }
      if (u == 1) {
        for (auto i: g[v]) {
          for (auto j: g[i]) {
            if (edge[j][n]) {
              min = std::min(min, w[1][v] + w[v][i] + w[i][j] + w[j][n]);
            }
          }
        }
      }
      if (v == n) {
        for (auto i: g[1]) {
          for (auto j: g[i]) {
            if (edge[j][u]) {
              min = std::min(min, w[1][i] + w[i][j] + w[j][u] + w[u][n]);
            }
          }
        }
      }
    }
    while (ans.size()) {
      std::cout << ans.top() << '\n';
      ans.pop();
    }
  }
  return 0;
}
