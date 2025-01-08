/**
 *    author:  feev1x
 *    created: 05.01.2025 16:09:19
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::vector<int>> r(n + 5, std::vector<int>(n + 5));
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      std::cin >> r[i][j];
    }
  }
  auto Dfs = [&](auto &&self, std::vector<int> a, int i) -> void {
    int mn = a[i], mx = a[i]; 
    for (int j = i - 1; j > 0; --j) {
      mn = std::min(mn, a[j]);
      mx = std::max(mx, a[j]);
      if (r[j][i] != mx - mn) {
        return;
      }
    }
    if (i == n) {
      for (int i = 1; i <= n; ++i) {
        std::cout << a[i] << " \n"[i == n];
      }
      exit(0);
    }
    if (a[i] + r[i][i + 1] <= 1e9) {
      a[i + 1] = a[i] + r[i][i + 1];
      self(self, a, i + 1);
    }
    if (a[i] - r[i][i + 1] >= -1e9) {
      a[i + 1] = a[i] - r[i][i + 1];
      self(self, a, i + 1);
    }
  };
  std::vector<int> a(n + 1);
  Dfs(Dfs, a, 1);
  return 0;
}
