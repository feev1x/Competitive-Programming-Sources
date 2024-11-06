/**
 *    author:  feev1x
 *    created: 05.11.2024 19:14:47
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  char s[50]; scanf("%s", s);  
  if (s[46] == 'R' || s[46] == 'U' || s[47] == 'R' || s[47] == 'U') {
    printf("0\n");
    return 0;
  }
  auto Check = [&](int i, int j) {
    return 0 <= i && i < 7 && 0 <= j && j < 7;
  };
  auto Can = [&](int i, int j, array<array<bool, 7>, 7> used) {
    queue<pair<int, int>> q;
    auto vis = used;
    q.emplace(i, j);
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (Check(nx, ny) && !vis[nx][ny]) {
          vis[nx][ny] = true;
          q.emplace(nx, ny);
        }
      }
    }
    for (int x = 0; x < 7; ++x) {
      for (int y = 0; y < 7; ++y) {
        if (!(vis[x][y] | used[x][y])) {
          return false;
        }
      }
    }
    for (int x = 0; x < 7; ++x) {
      for (int y = x == 6 ? 1 : 0; y < 7; ++y) {
        if (used[x][y]) continue;
        int cnt = 0, cntb = 0, cnt2 = 0, cnt4 = 0;
        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!Check(nx, ny)) {
            if (k < 2) cnt2++;
            else cnt4++;
            cnt++;
          }
          if (Check(nx, ny) && used[nx][ny]) {
            if (nx == i && ny == j) cnt = -1e9;
            if (k < 2) cnt2++;
            else cnt4++;
            cnt++;
          }
        }
        if (cnt >= 3) {
          return false;
        }
      }
    }
    return true;
  };
  function<int(int, int, array<array<bool, 7>, 7>, int)> Count = [&](int i, int j, array<array<bool, 7>, 7> used, int c) {
    used[i][j] = true;
    if (c == 48) {
      if (i == 6 && j == 0) {
        return 1;
      }
      return 0;
    }
    if (used[6][0]) {
      return 0;
    }
    if (!Can(i, j, used)) {
      return 0;
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    string nw = "DURL";
    int cnt = 0;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (Check(x, y) && !used[x][y] && (s[c] == '?' || s[c] == nw[k])) {
        cnt += Count(x, y, used, c + 1);
      }
    }
    return cnt;
  };
  array<array<bool, 7>, 7> used{};
  printf("%d\n", Count(0, 0, used, 0));
  return 0;
}
