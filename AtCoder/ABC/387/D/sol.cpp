/**
 *    author:  feev1x
 *    created: 04.01.2025 19:01:45
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int h, w; std::cin >> h >> w;
  std::vector<std::string> s(h);
  std::vector<std::vector<std::array<int, 2>>> dis(h, std::vector<std::array<int, 2>>(w + 1, {INF, INF}));
  int sx, sy, gx, gy;
  for (int i = 0; i < h; ++i) {
    std::cin >> s[i];
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == 'S') {
        sx = i, sy = j;
      } else if (s[i][j] == 'G') {
        gx = i, gy = j;
      }
    }
  }
  int dx[]{1, -1, 0, 0};
  int dy[]{0, 0, 1, -1};
  std::queue<std::tuple<int, int, int>> q;
  q.emplace(sx, sy, 2);
  auto Check = [&](int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w && s[i][j] != '#';
  };
  while (q.size()) {
    auto [x, y, nw] = q.front();
    q.pop();
    if (nw != 0) {
      for (int k = 0; k < 2; ++k) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (Check(i, j) && (x == sx && y == sy || dis[i][j][0] > dis[x][y][nw] + 1)) {
          dis[i][j][0] = (x == sx && y == sy ? 0 : dis[x][y][nw]) + 1;
          q.emplace(i, j, 0);
        }
      }
    }
    if (nw != 1) {
      for (int k = 2; k < 4; ++k) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (Check(i, j) && (x == sx && y == sy || dis[i][j][1] > dis[x][y][nw] + 1)) {
          dis[i][j][1] = (x == sx && y == sy ? 0 : dis[x][y][nw]) + 1;
          q.emplace(i, j, 1);
        }
      }
    }
  }
  int res = INF;
  for (int i = 0; i < 2; ++i) {
    if (dis[gx][gy][i] < res) {
      res = dis[gx][gy][i];
    }
  }
  if (res == INF) {
    res = -1;
  }
  std::cout << res << '\n';
  return 0;
}
