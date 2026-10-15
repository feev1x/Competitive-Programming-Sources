#include <bits/stdc++.h>

#define int int64_t

constexpr int64_t INF = 1e18;

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  std::vector<int64_t> p(n + 1);
  for (auto &u: a) std::cin >> u;
  for (auto &u: b) std::cin >> u;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 0; i + 1 < n; ++i) {
    g[i].emplace_back(i + 1, a[i]);
    g[i + 1].emplace_back(i, a[i]);
  }
  g[0].emplace_back(n - 1, a[n - 1]);
  g[n - 1].emplace_back(0, a[n - 1]);
  for (int i = 0; i < n; ++i) {
    p[i + 1] = p[i] + a[i];
    g[i].emplace_back(n, b[i]);
    g[n].emplace_back(i, b[i]);
  }
  std::vector<int64_t> d(n + 1, INF);
  std::set<std::pair<int64_t, int>> st;
  d[n] = 0;
  st.emplace(0, n);
  while (st.size()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for (auto [to, w]: g[v]) if (d[to] > d[v] + w) {
      st.erase({d[to], to});
      d[to] = d[v] + w;
      st.emplace(d[to], to);
    }
  }
  while (q--) {
    int s, t; std::cin >> s >> t; --s, --t;
    if (t == n) {
      std::cout << d[s] << '\n';
      continue;
    }
    int64_t res = d[s] + d[t];
    res = std::min(res, p[t] - p[s]);
    res = std::min(res, p.back() - p[t] + p[s]);
    std::cout << res << '\n';
  }
  return 0;
}
