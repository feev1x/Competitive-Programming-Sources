#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, d; std::cin >> n >> d;
  std::vector<std::pair<int, int>> x(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i].first, x[i].second = i + 1;
  std::sort(x.begin(), x.end());
  std::set<int> st;
  for (int i = 0; i < n; ++i) {
    int d1 = d, d2 = d;
    if (i) d1 = std::abs(x[i].first - x[i - 1].first);
    if (i + 1 < n) d2 = std::abs(x[i].first - x[i + 1].first);
    if (std::min(d1, d2) >= d) st.emplace(x[i].second);
  }
  std::cout << st.size() << '\n';
  for (auto u: st) std::cout << u << ' ';
  return 0;
}
