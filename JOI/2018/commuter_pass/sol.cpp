#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

#define pr std::pair<int64_t, int>
#define tpl std::tuple<int64_t, int, int>
  
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, S, T, U, V; std::cin >> n >> m >> S >> T >> U >> V;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c; std::cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  std::vector<int64_t> ds(n + 1, INF), dt(n + 1, INF);
  {
    std::priority_queue<pr, std::vector<pr>, std::greater<pr>> pq;
    ds[S] = 0;
    pq.emplace(0, S);
    while (pq.size()) {
      auto [_, v] = pq.top(); pq.pop();
      if (_ != ds[v]) continue;
      for (auto [to, w]: g[v]) if (ds[to] > ds[v] + w) {
        ds[to] = ds[v] + w;
        pq.emplace(ds[to], to);
      }
    }
    dt[T] = 0;
    pq.emplace(0, T);
    while (pq.size()) {
      auto [_, v] = pq.top(); pq.pop();
      if (_ != dt[v]) continue;
      for (auto [to, w]: g[v]) if (dt[to] > dt[v] + w) {
        dt[to] = dt[v] + w;
        pq.emplace(dt[to], to);
      }
    }
  }
  std::vector d(n + 1, std::array<int64_t, 4>{INF, INF, INF, INF});
  d[U][0] = 0;
  std::priority_queue<tpl, std::vector<tpl>, std::greater<tpl>> pq;
  pq.emplace(d[U][0], U, 0);
  auto Check = [&](int u, int v, int w) {
    if (ds[u] + dt[v] + w != ds[T] && ds[v] + dt[u] + w != ds[T]) return 0;
    return 1 + (ds[u] < ds[v]);
  };
  while (pq.size()) {
    auto [_, v, nw] = pq.top(); pq.pop();
    if (_ != d[v][nw]) continue;
    for (auto [to, w]: g[v]) {
      int nx = (nw == 0 ? 0 : 3);
      if (d[to][nx] > d[v][nw] + w) {
        d[to][nx] = d[v][nw] + w;
        pq.emplace(d[to][nx], to, nx);
      }
      int got = Check(v, to, w);
      if (nw == 3 || !got || nw && nw != got) continue;
      if (d[to][got] > d[v][nw]) {
        d[to][got] = d[v][nw];
        pq.emplace(d[to][got], to, got);
      }
    }
  }
  std::cout << *std::min_element(d[V].begin(), d[V].end()) << '\n';
  return 0;
}
