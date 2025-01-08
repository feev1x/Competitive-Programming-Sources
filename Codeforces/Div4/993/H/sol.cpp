/**
 *    author:  feev1x
 *    created: 18.12.2024 13:48:53
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, q; std::cin >> n >> q;
    std::vector<std::vector<i64>> px(n + 1, std::vector<i64>(n + 1));
    std::vector<std::vector<i64>> p(n + 1, std::vector<i64>(n + 1));
    std::vector<std::vector<i64>> py(n + 1, std::vector<i64>(n + 1));
    std::vector<std::vector<int>> m(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> m[i][j];
        p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + m[i][j];
        px[i + 1][j + 1] = px[i + 1][j] + px[i][j + 1] - px[i][j] + m[i][j] * (i + 1);
        py[i + 1][j + 1] = py[i + 1][j] + py[i][j + 1] - py[i][j] + m[i][j] * (j + 1);
      }
    }
    while (q--) {
      int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--;
      i64 sum_x = px[x2][y2] - px[x1][y2] - px[x2][y1] + px[x1][y1];
      i64 sum_y = py[x2][y2] - py[x1][y2] - py[x2][y1] + py[x1][y1];
      i64 sum = p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
      int df = y2 - y1;
      // (y2 - y1 + 1) * sum(MxyX) - x1 * y2 * sum(Mxy) + x1 * (y1 - 1) * sum(Mxy) + (1 - y1) * sum(MxyY) + sum(Mxy)
      x1++;
      std::cout << df * sum_x - (x1 * df + y1) * sum + sum_y << " \n"[!q];
    }
  }
  return 0;
}
