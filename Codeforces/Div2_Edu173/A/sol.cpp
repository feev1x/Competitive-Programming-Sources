/**
 *    author:  feev1x
 *    created: 24.12.2024 20:36:10
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    i64 n; std::cin >> n;
    i64 cnt = 1;
    while (n > 3) {
      n /= 4;
      cnt *= 2;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
