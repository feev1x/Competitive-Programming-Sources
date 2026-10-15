#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> c(n), x(n), y(n);
  for (auto &u: c) std::cin >> u;
  for (auto &u: x) std::cin >> u;
  for (auto &u: y) std::cin >> u;
  int res = 0;
  for (int c1 = 0; ; ++c1) {
    bool flag = true;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      if (c[i] < c1 * x[i]) {
        flag = false;
        break;
      }
      if (y[i]) ans = std::min(ans, (c[i] - c1 * x[i]) / y[i]);
    }
    if (!flag) break;
    res = std::max(res, ans + c1);
  }
  std::cout << res << '\n';
  return 0;
}
