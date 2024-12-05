/**
 *    author:  feev1x
 *    created: 24.11.2024 11:40:28
**/
#include <bits/stdc++.h>

using i64 = long long;

char S[12];

int main() {
  std::array<std::array<int, 12>, 12> a{};
  for (int i = 0; i < 12; ++i) {
    scanf("%s", S);
    std::string s = S;
    for (int j = 0; j < 12; ++j) {
      a[i][j] = s[i] - '0';
    }
  }
  int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
  int dy[] = {0, 1, -1, -1, 1, 0, 1, -1};
  int dp[12][12][12][12][2]{};
  bool used[12][12][12][12][2]{};
  bool nw[12][12][12][12][2]{};
  auto Check = [&](int i, int j) {
    return 0 <= i && i < 12 && 0 <= j && j < 12;
  };
  std::function<int(int, int, int, int, bool)> Dfs = [&](int i, int j, int x, int y, bool flag) {
    if (nw[i][j][x][y][flag]) {
      return -1; 
    }
    if (used[i][j][x][y][flag]) {
      return dp[i][j][x][y][flag];
    }
    used[i][j][x][y][flag] = true;
    nw[i][j][x][y][flag] = true;
    int res = 0;
    if (flag) {
      for (int ni = 0; ni < 12; ++ni) {
        for (int nj = 0; nj < 12; ++nj) {
          if (ni == i && nj == j) {
            continue;
          }
          if (ni + nj == i + j || ni - nj == i - j || ni == i || nj == j) {
            if (ni == x && nj == y) {
              return dp[i][j][x][y][flag] = 1;
            }
            if (a[ni][nj] == 1) {
              int dfs = Dfs(ni, nj, x, y, false);
              if (dfs == 0 || dfs == -1) continue;
              if (res == 0 || res > dfs + 1) {
                res = dfs + 1;
              }
            }
          }
        }
      }
    } else {
      for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (Check(nx, ny) && (nx != i || ny != j)) {
          int dfs = Dfs(i, j, nx, ny, true);
          if (dfs == -1) {
            continue;
          }
          if (dfs == 0) {
            return dp[i][j][x][y][flag] = 0;
          }
          if (dfs > res) {
            res = dfs;
          }
        }
      }
    }
    nw[i][j][x][y][flag] = false;
    return dp[i][j][x][y][flag] = res;
  };
  int i, j; scanf("%d%d", &i, &j);
  int x, y; scanf("%d%d", &x, &y);
  i--, j--, x--, y--;
  printf("%d\n", Dfs(i, j, x, y, true));
  return 0;
}
