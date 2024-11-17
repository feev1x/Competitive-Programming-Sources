/**
 *    author:  feev1x
 *    created: 14.11.2024 10:56:31
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int x; scanf("%d", &x);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  a.emplace(a.begin(), 0);
  if (a[1] >= x) {
    x /= 2;
  }
  std::deque<std::pair<int, int>> dq;
  std::vector<int> dis(n + 1);
  dis[1] = x;
  dq.emplace_back(1, x);
  while (!dq.empty()) {
    auto [cur, num] = dq.front();
    dq.pop_front();
    for (auto to: g[cur]) {
      int nx = num;
      if (a[to] >= num) {
        nx /= 2;
      }
      if (dis[to] < nx) {
        dis[to] = nx;
        if (nx == num) {
          dq.emplace_front(to, nx);
        } else {
          dq.emplace_back(to, nx);
        }
      }
    }
  }
  printf("%d\n", dis[n]);
  return 0;
}
