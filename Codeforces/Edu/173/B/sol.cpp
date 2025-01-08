/**
 *    author:  feev1x
 *    created: 24.12.2024 20:40:12
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, d; std::cin >> n >> d;
    std::cout << 1;
    if (d == 3 || n > 2 || n * d % 3 == 0) {
      std::cout << ' ' << 3;
    }
    if (d == 5) {
      std::cout << ' ' << 5;
    }
    int fac = 1;
    if (n < 9) {
      for (int i = 2; i <= n; ++i) {
        fac *= i;
      }
    }
    if (d == 7 || n > 5 || fac % 6 == 0) {
      std::cout << ' ' << 7;
    }
    if (d == 9 || n > 8 || fac * d % 9 == 0) {
      std::cout << ' ' << 9;
    }
    std::cout << '\n';
  }
  return 0;
}
