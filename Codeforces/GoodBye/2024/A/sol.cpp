/**
 *    author:  feev1x
 *    created: 28.12.2024 20:39:23
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) {
      std::cin >> u;
    }
    bool flag = false;
    for (int i = 1; i < n; ++i) {
      if (std::abs(a[i] - a[i - 1]) < std::min(a[i], a[i - 1])) {
        flag = true;
        break;
      }
    }
    std::cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
