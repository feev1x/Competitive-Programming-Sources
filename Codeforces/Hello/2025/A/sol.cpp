/**
 *    author:  feev1x
 *    created: 04.01.2025 20:36:09
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, m; std::cin >> n >> m;
    std::cout << std::max(n, m) + 1 << '\n';
  }
  return 0;
}
