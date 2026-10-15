#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> h(n), p(n), df(n);
  for (auto &u: h) std::cin >> u;
  for (auto &u: p) std::cin >> u;
  std::vector<std::pair<int, int>> b;
  for (int i = 0; i < n; ++i) b.emplace_back(p[i], i);
  std::sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    df[i] = p[i] - h[i];
    if (df[i] < 0) return std::cout << "-1\n", void();
  }
  for (int i = 1; i < n; ++i)
    if (df[b[i].second] < df[b[i - 1].second] || h[b[i].second] < h[b[i - 1].second] || b[i].first == b[i - 1].first && h[b[i].second] != h[b[i - 1].second]) return std::cout << "-1\n", void();
  std::cout << *std::max_element(df.begin(), df.end()) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
