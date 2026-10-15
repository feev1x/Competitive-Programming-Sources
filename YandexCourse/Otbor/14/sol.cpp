#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, x, y, z; std::cin >> n >> x >> y >> z;
  std::vector<int> l(n), pw(n + 1, 1);
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 4;
  for (auto &u: l) std::cin >> u;
  int res = INF; 
  for (int mask = 0; mask < pw[n]; ++mask) {
    int X = 0, Y = 0, Z = 0, mana = 0;
    for (int i = 0; i < n; ++i) {
      switch (mask / pw[i] % 4) {
        case 1:
          if (X) mana += 10;
          X += l[i];
          break;
        case 2:
          if (Y) mana += 10;
          Y += l[i];
          break;
        case 3:
          if (Z) mana += 10;
          Z += l[i];
          break;
        default:
          break;
      }
    }
    if (!X || !Y || !Z) continue;
    mana += std::abs(X - x);
    mana += std::abs(Y - y);
    mana += std::abs(Z - z);
    res = std::min(res, mana);
  }
  std::cout << res << '\n';
  return 0;
}
