#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int l, h; std::cin >> l >> h;
  if (l & 1) std::cout << h << '\n';
  else std::cout << (h / 2) * 2 << '\n';
  return 0;
}
