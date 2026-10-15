#include <bits/stdc++.h>

inline void solve() {
  int n, m; std::cin >> n >> m;
  std::vector<int> v(n);
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto &u: v) std::cin >> u;
  for (auto &u: a) for (auto &v: u) std::cin >> v;
  std::multiset<int> st;
  int res = m;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) st.emplace(a[i][j]);
    auto it = --st.end();
    int sum = 0;
    for (int j = 1; j <= m; ++j, --it) {
      sum += *it;
      if (sum >= v[i]) {
        res = std::min(res, j);
        break;
      }
    }
  }
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
