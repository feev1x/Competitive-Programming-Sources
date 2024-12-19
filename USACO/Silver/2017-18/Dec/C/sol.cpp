/**
 *    author:  feev1x
 *    created: 18.12.2024 16:21:57
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("shuffle.in", "r", stdin);
  std::freopen("shuffle.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> p(n), used(n);
  for (auto &u: p) {
    std::cin >> u;
    u--;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    int u = i;
    bool flag = false;
    while (true) {
      if (used[u] == i + 1) {
        flag = true;
        break;
      } else if (used[u]) {
        break;
      }
      used[u] = i + 1;
      u = p[u];
    }
    if (flag) {
      for (int v = p[u]; v != u; v = p[v]) {
        cnt++;
      }
      cnt++;
    }
  }
  std::cout << cnt << '\n';
  return 0;
}
