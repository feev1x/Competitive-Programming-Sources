/**
 *    author:  feev1x
 *    created: 04.01.2025 18:02:13
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x; std::cin >> x;
  int sum = 0;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if (i * j != x) {
        sum += i * j;
      }
    }
  }
  std::cout << sum << '\n';
  return 0;
}
