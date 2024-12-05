/**
 *    author:  feev1x
 *    created: 24.11.2024 10:21:51
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 705;

char S[SZ];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::string> s(n);
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
  auto Check = [&](int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
  };
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  int sz = 0;
  bool black = false, white = false;
  std::function<void(int, int)> Dfs = [&](int i, int j) {
    used[i][j] = true;
    sz++;
    for (int k = 0; k < 4; ++k) {
      int x = dx[k] + i;
      int y = dy[k] + j;
      if (Check(x, y) && !used[x][y]) {
        if (s[x][y] == 'B') {
          black = true;
        } else if (s[x][y] == 'W') {
          white = true;
        } else {
          Dfs(x, y);
        }
      }
    }
  };
  int ans[2]{};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (used[i][j] || s[i][j] != '.') continue;
      Dfs(i, j);
      if (black ^ white) {
        if (black) {
          ans[0] += sz;
        } else {
          ans[1] += sz;
        }
      }
      sz = 0;
      black = false, white = false;
    }
  }
  printf("%d\n", ans[0] - ans[1]);
  return 0;
}
