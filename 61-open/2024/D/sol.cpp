/**
 *    author:  feev1x
 *    created: 24.11.2024 10:41:11
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::vector<i64>> h(n, std::vector<i64>(m));
  i64 sum = 0;
  for (auto &u: h) {
    for (auto &v: u) {
      scanf("%lld", &v);
      sum += (v > 0);
    }
  }
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  auto Check = [&](int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
  };
  auto Count = [&](int i, int j) {
    i64 sm = 0;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (!Check(x, y)) {
        sm += h[i][j];
      } else if (h[x][y] < h[i][j]) {
        sm += h[i][j] - h[x][y];
      }
    }
    return sm;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      sum += Count(i, j);
    }
  }
  i64 mx = -i64(INFINITY), mn = i64(INFINITY);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      i64 sm = sum - Count(i, j);
      h[i][j]++;
      sm += Count(i, j);
      for (int k = 0; k < 4; ++k) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (Check(x, y)) {
          h[i][j]--;
          sm -= Count(x, y);
          h[i][j]++;
          sm += Count(x, y);
        }
      }
      if (h[i][j] == 1) sm++;
      mx = std::max(mx, sm);
      mn = std::min(mn, sm);
      h[i][j]--;
    }
  }
  printf("%lld %lld\n", mn, mx);
  return 0;
}
