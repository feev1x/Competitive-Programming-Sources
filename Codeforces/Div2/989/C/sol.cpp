/**
 *    author:  feev1x
 *    created: 30.11.2024 20:58:01
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1001;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; scanf("%d%d", &n, &m);  
    std::vector<std::string> s(n);
    for (auto &u: s) {
      scanf("%s", S);
      u = S;
    }
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};
    std::map<std::pair<int, int>, char> dir;
    dir[{1, 0}] = 'D';
    dir[{-1, 0}] = 'U';
    dir[{0, 1}] = 'R';
    dir[{0, -1}] = 'L';
    std::vector<std::pair<int, int>> sm;
    auto Check = [&](int i, int j) {
      return 0 <= i && i < n && 0 <= j && j < m;
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '?') {
          for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (Check(x, y) && (dir[{-dx[k], -dy[k]}] == s[x][y] || s[x][y] == '?')) {
              s[i][j] = dir[{dx[k], dy[k]}];
              if (s[x][y] == '?') {
                s[x][y] = dir[{-dx[k], -dy[k]}];
              }
              break;
            }
          }
        }
      }
    }
    std::vector cyc(n, std::vector<bool>(m));
    std::vector used(n, std::vector<int>(m));
    int nw = 1, cnt = 0;
    std::function<void(int, int)> Dfs = [&](int i, int j) {
      used[i][j] = nw;
      for (int k = 0; k < 4; ++k) {
        if (dir[{dx[k], dy[k]}] != s[i][j]) {
          continue;
        }
        int x = i + dx[k];
        int y = j + dy[k];
        if (!Check(x, y)) {
          break;
        }
        if (!used[x][y]) {
          Dfs(x, y);
        } else if (used[x][y] == nw) {
          cyc[i][j] = true;
          cnt++;
        }
        if (cyc[x][y] && !cyc[i][j]) {
          cyc[i][j] = true;
          cnt++;
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!used[i][j] && s[i][j] != '?') {
          Dfs(i, j);
          nw++;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '?') {
          for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (Check(x, y) && cyc[x][y]) {
              cyc[i][j] = true;
              cnt++;
              break;
            }
          }
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
