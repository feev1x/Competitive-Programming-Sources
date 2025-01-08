/**
 *    author:  feev1x
 *    created: 20.12.2024 21:11:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, x, y; std::cin >> n >> x >> y; x--, y--;
    std::vector<int> a(n);
    for (int i = 1; i < n; ++i) {
      a[i] = i & 1;
    }
    if (n & 1) {
      a[0] = 2;
    }
    if ((x & 1) == (y & 1)) {
      a[x] = 2;
      if (x > 0 && a[x] == a[x - 1]) {
        a[x - 1] = 1;
      }
      if (x - 2 >= 0 && a[x - 1] == 1 && a[x - 2] == 2 && a[x] == 2) {
        a[x - 1] = 0, a[x - 2] = 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
