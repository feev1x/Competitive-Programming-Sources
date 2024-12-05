/**
 *    author:  feev1x
 *    created: 29.11.2024 22:34:20
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("lightson.in", "r", stdin);
  std::freopen("lightson.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  std::vector used(n + 1, std::vector<bool>(n + 1));
  std::vector lit(n + 1, std::vector<bool>(n + 1));
  lit[1][1] = true;
  std::vector sw(n + 1, std::vector(n + 1, std::vector<std::pair<int, int>>()));
  for (int i = 0; i < m; ++i) {
    int x, y, a, b; scanf("%d%d%d%d", &x, &y, &a, &b);
    sw[x][y].emplace_back(a, b);
  }
  int dx[]{1, -1, 0, 0};
  int dy[]{0, 0, 1, -1};
  auto Check = [&](int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
  };
  std::function<void(int, int)> Dfs = [&](int i, int j) {
    used[i][j] = true;
    for (auto [x, y]: sw[i][j]) {
      if (used[x][y]) {
        continue;
      }
      lit[x][y] = true;
      for (int k = 0; k < 4; ++k) {
        int _x = dx[k] + x;
        int _y = dy[k] + y;
        if (Check(_x, _y) && used[_x][_y]) {
          Dfs(x, y);
          break;
        }
      }
    }
    for (int k = 0; k < 4; ++k) {
      int x = dx[k] + i;
      int y = dy[k] + j;
      if (Check(x, y) && lit[x][y] && !used[x][y]) {
        Dfs(x, y);
      }
    }
  };
  Dfs(1, 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cnt += lit[i][j];
    }
  }
  printf("%d\n", cnt); 
  return 0;
}
