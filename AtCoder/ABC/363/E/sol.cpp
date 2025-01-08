/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, w, y; cin >> h >> w >> y;
  vector<vector<int>> a(h + 1, vector<int>(w + 1));
  vector<vector<bool>> db(h + 1, vector<bool>(w + 1));
  vector<set<pair<int, int>>> cnt(y + 1);
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      cin >> a[i][j];
      if (a[i][j] <= y && (i == h || j == w || i == 1 || j == 1)) {
        cnt[a[i][j]].emplace(i, j);
        db[i][j] = true;
      }
    }
  }
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  auto check = [&](int i, int j) {
    return i >= 1 && i <= h && j >= 1 && j <= w && (!db[i][j]) && a[i][j] <= y;
  };
  int area = h * w;
  function<void(int, int, int)> fun = [&](int i, int j, int I) -> void {
    for (int k = 0; k < 4; ++k) {
      int X = dx[k] + i;
      int Y = dy[k] + j;
      if (check(X, Y)) {
        if (a[X][Y] <= I) {
          db[X][Y] = true;
          fun(X, Y, I);
        } else {
          db[X][Y] = true;
          cnt[a[X][Y]].emplace(X, Y);
        }
      }
    }
    area--;
  };
  for (int I = 1; I <= y; ++I) {
    vector<pair<int, int>> del;
    for (auto [i, j]: cnt[I]) {
      fun(i, j, I);
    }
    cnt[I].clear();
    cout << area << '\n';
  }
}

