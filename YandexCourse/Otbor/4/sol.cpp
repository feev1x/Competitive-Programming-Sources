#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, y; std::cin >> n >> y;
  int a1 = -1, a2 = -1, a3 = -1;
  for (int c1 = 0; c1 <= n; ++c1) {
    for (int c2 = 0; c1 + c2 <= n; ++c2) {
      int c3 = n - c1 - c2;
      if (c1 * 10000LL + c2 * 5000LL + c3 * 1000LL == y) {
        std::cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
        return 0;
      }
    }
  }
  std::cout << "-1 -1 -1\n";
  return 0;
}
