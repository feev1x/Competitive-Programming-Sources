#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k; std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n);
  std::vector<int> p(k), h(k), d(n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b; std::cin >> a >> b; --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < k; ++i) {
    std::cin >> p[i] >> h[i]; --p[i];
    d[p[i]] = std::max(d[p[i]], h[i]);
    st.emplace(d[p[i]], p[i]);
  }
  while (st.size()) {
    int v = st.rbegin()->second; st.erase(--st.end());
    for (auto to: g[v]) {
      if (d[to] < d[v] - 1) {
        st.erase({d[to], to});
        d[to] = d[v] - 1;
        st.emplace(d[to], to);
      }
    }
  }
  std::vector<int> res;
  for (int i = 0; i < n; ++i) if (d[i] >= 0) res.emplace_back(i + 1);
  std::cout << res.size() << '\n';
  for (auto u: res) std::cout << u << ' ';
  return 0;
}
