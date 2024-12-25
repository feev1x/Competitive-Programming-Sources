/**
 *    author:  feev1x
 *    created: 19.12.2024 20:36:45
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int x; std::cin >> x;
    std::cout << (x % 33 == 0 ? "YES\n" : "NO\n");
  }
  return 0;
}
