/**
 *    author:  feev1x
 *    created: 04.01.2025 20:56:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int l, r; std::cin >> l >> r;
    int a = 0, b = 0, c = 0;
    for (int i = 29; i >= 0; --i) {
      if ((l >> i & 1) ^ (r >> i & 1)) {
        a |= 1 << i, b |= (1 << i) - 1;
        break;
      }
      if (l >> i & 1) {
        a |= 1 << i;
        b |= 1 << i;
      }
    }
    if (l == b) {
      c = a + 1;
    } else {
      c = b - 1;
    }
    std::cout << a << ' ' << b << ' ' << c << '\n';
  }
  return 0;
}
