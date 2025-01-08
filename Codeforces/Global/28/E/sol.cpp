/**
 *    author:  feev1x
 *    created: 19.12.2024 23:09:02
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, m; std::cin >> n >> m;
    if (m > 2 * n - 1) {
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
    std::vector<std::vector<int>> g(2 * n + 1);
    std::deque<int> dq;
    for (int i = 1; i <= n; ++i) {
      dq.emplace_back(i);
      dq.emplace_back(i);
    }
    for (int i = 1; i <= m; ++i) {
      int j = 1;
      for (auto u: dq) {
        g[j++].emplace_back(u);
      }
      dq.emplace_back(dq.front());
      dq.pop_front();
    }
    for (int i = 1; i <= 2 * n; ++i) {
      for (auto v: g[i]) {
        std::cout << v << ' ';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
