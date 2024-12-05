/**
 *    author:  feev1x
 *    created: 02.12.2024 17:27:02
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MX = 101;

int main() {
  std::freopen("pails.in", "r", stdin);
  std::freopen("pails.out", "w", stdout);
  int x, y, k, m; scanf("%d%d%d%d", &x, &y, &k, &m);
  int res = m;
  bool used[MX][MX][MX]{};
  std::function<void(int, int, int)> Dfs = [&](int i, int j, int cnt) {
    if (used[i][j][cnt]) {
      return;
    }
    res = std::min(res, std::abs(m - (i + j)));
    for (int l = cnt; l <= k; ++l) {
      used[i][j][l] = true;
    }
    if (cnt == k) {
      return;
    }
    Dfs(x, j, cnt + 1);
    Dfs(i, y, cnt + 1);
    Dfs(0, j, cnt + 1);
    Dfs(i, 0, cnt + 1);
    Dfs(std::max(0, i - (y - j)), std::min(i + j, y), cnt + 1);
    Dfs(std::min(i + j, x), std::max(0, j - (x - i)), cnt + 1);
  };
  Dfs(0, 0, 0);
  printf("%d\n", res);
  return 0;
}
