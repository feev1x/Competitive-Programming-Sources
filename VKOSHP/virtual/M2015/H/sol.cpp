/**
 *    author:  feev1x
 *    created: 13.11.2024 11:44:41
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1e9;

int main() {
//  std::freopen("h.in", "r", stdin);
//  std::freopen("h.out", "w", stdout);
  int n, m; scanf("%d%d", &n, &m);
  char S[m + 1];
  std::vector<std::string> s(n);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  std::vector dis(n, std::vector(m, std::array<int, 4>{0, inf, inf, inf}));
  std::deque<std::tuple<int, int, int>> dq;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1') {
        dis[i][j][1] = 0;
        dq.emplace_back(i, j, 1);
      }
      if (s[i][j] == '2') {
        dis[i][j][2] = 0;
        dq.emplace_back(i, j, 2);
      }
      if (s[i][j] == '3') {
        dis[i][j][3] = 0;
        dq.emplace_back(i, j, 3);
      }
    }
  }
  auto Check = [&](int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#';
  };
  while (!dq.empty()) {
    auto [i, j, comp] = dq.front();
    dq.pop_front();
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && dis[x][y][comp] > dis[i][j][comp] + (s[x][y] == '.')) {
        dis[x][y][comp] = dis[i][j][comp] + (s[x][y] == '.');
        if (s[x][y] == '.') {
          dq.emplace_back(x, y, comp);
        } else {
          dq.emplace_front(x, y, comp);
        }
      }
    }
  }
  int res = inf;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] != '#') {
        res = std::min((i64)res, (i64)dis[i][j][1] + dis[i][j][2] + dis[i][j][3] - (s[i][j] == '.' ? 2 : 0));
      }
    }
  }
  if (res == inf) res = -1;
  printf("%d\n", res);
  return 0;
}
