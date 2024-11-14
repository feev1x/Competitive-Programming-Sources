/**
 *    author:  feev1x
 *    created: 22.10.2024 19:06:44
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for (auto &u: s) cin >> u;
  vector<vector<bool>> zem(h, vector<bool>(w)), oz(h, vector<bool>(w));
  auto Check = [&](int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w;
  };
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  function<void(int, int)> Dfs = [&](int i, int j) {
    if (zem[i][j]) return;
    zem[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && !zem[x][y] && s[x][y] == '.') {
        Dfs(x, y);
      }
    }
  };
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.' && (i == 0 || j == 0 || i == h - 1 || j == w - 1)) {
        Dfs(i, j);
      }
    }
  }
  int hei = 1e9, jei = 0;
  Dfs = [&](int i, int j) {
    if (oz[i][j]) return;
    if (i - 1 < hei) {
      hei = i - 1;
      jei = j;
    }
    oz[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && !oz[x][y] && s[x][y] == '.') {
        Dfs(x, y);
      }
    }
  };
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!zem[i][j] && s[i][j] == '.') {
        Dfs(i, j);
        goto exit;
      }
    }
  }
exit:
  queue<pair<int, int>> q;
  q.emplace(hei, jei);
  vector<vector<bool>> used(h, vector<bool>(w));
  vector<vector<pair<int, int>>> p(h, vector<pair<int, int>>(w));
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (i < hei) continue;
    for (int k = 0; k < (i == hei ? 3 : 4); ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && s[x][y] == '#' && !used[x][y]) {
        used[x][y] = true;
        p[x][y] = {i, j};
        debug(x, y, i, j);
        q.emplace(x, y);
      }
    }
  }
  vector<string> ans(h, string(w, '.'));
  ans[hei][jei] = '#';
  for (auto [x, y] = p[hei][jei]; x != hei || y != jei; tie(x, y) = p[x][y]) {
    ans[x][y] = '#';
  }
  for (auto u: ans) {
    cout << u << '\n';
  }
  return 0;
}
