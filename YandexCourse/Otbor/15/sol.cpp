#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int x1, y1; std::cin >> x1 >> y1;
  int x2, y2; std::cin >> x2 >> y2;
  if (x1 == x2 && y1 == y2) {
    std::cout << "0\n";
    exit(0);
  }
  if (x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2 || std::abs(x1 - x2) + std::abs(y1 - y2) < 4) {
    std::cout << "1\n";
    exit(0);
  }
  if (((x1 - y1) - (x2 - y2)) % 2 == 0 || ((x1 + y1) - (x2 + y2)) % 2 == 0 || std::abs((x1 + y1) - (x2 + y2)) <= 3 || std::abs((x1 - y1) - (x2 - y2)) <= 3 || std::abs(x1 - x2) + std::abs(y1 - y2) < 7) {
    std::cout << "2\n";
    return 0;
  }
  std::cout << "3\n";
  return 0;
}
