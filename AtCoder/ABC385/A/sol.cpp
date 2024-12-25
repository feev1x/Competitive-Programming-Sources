/**
 *    author:  feev1x
 *    created: 21.12.2024 18:03:51
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b, c; std::cin >> a >> b >> c;
  if (std::max({a, b, c}) == std::min({a, b, c}) || a + b + c == std::max({a, b, c}) * 2) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}
