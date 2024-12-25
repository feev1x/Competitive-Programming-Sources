/**
 *    author:  feev1x
 *    created: 24.12.2024 21:44:34
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    i64 l, r, g; std::cin >> l >> r >> g;
    i64 ld = (l + g - 1) / g, rd = r / g;
    i64 a = -1, b = -1;
    for (i64 dif = rd - ld; dif >= 0; --dif) {
      for (i64 lf = ld; lf + dif <= rd; ++lf) {
        if (std::gcd(lf, lf + dif) == 1) {
          a = lf * g, b = (lf + dif) * g;
          goto end;
        }
      }
    }
end: std::cout << a << ' ' << b << '\n';
  }
  return 0;
}
