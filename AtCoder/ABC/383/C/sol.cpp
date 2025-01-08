/**
 *    author:  feev1x
 *    created: 07.12.2024 18:13:30
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15;

char S[MXSZ];

inline int dis(int x1, int y1, int x2, int y2) {
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main() {
  int h, w, D; scanf("%d%d%d", &h, &w, &D);
  std::vector<std::string> s(h);
  std::vector<std::vector<bool>> used(h, std::vector<bool>(w, -1));
  std::vector<std::vector<int>> min(h, std::vector<int>(w, 1e9));
  int j = 0;
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
  }
  int res = 0;
  int dx[]{-1, 1, 0, 0};
  int dy[]{0, 0, -1, 1};
  auto Check = [&](int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
  };
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == 'H') {
        min[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  while (q.size()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && s[x][y] == '.' && min[x][y] > min[i][j] + 1) {
        min[x][y] = min[i][j] + 1;
        q.emplace(x, y);
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (min[i][j] <= D) {
        res++;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
