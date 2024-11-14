/**
 *    author:  feev1x
 *    created: 23.10.2024 15:04:10
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
  int n, m; cin >> n >> m;
  vector a(n + 1, vector<int>(m + 1));
  int mgx = 0, mgy = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  auto Check = [&](int i, int j, int v1, int v2) {
    if (i < 1 || i > n || j < 1 || j > m) return true;
    return a[i][j] == v1 || a[i][j] == v2;
  };
  auto Check1 = [&](int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m) return true;
    if (i == mgx && j == mgy) return false;
    switch(a[i][j]) {
      case 1:
        return i > mgx;
      case 5:
        return i < mgx;
      case 7:
        return j > mgy;
      case 3:
        return j < mgy;
      case 2:
        return i > mgx;
      case 6:
        return i < mgx;
      case 8:
        return i > mgx;
      default:
        return i < mgx;
    }
  };
  vector b(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int cnt = 0;
      cnt += Check(i - 1, j, 1, 5) + Check(i + 1, j, 1, 5);
      cnt += Check(i, j - 1, 7, 3) + Check(i, j + 1, 7, 3);
      cnt += Check(i - 1, j - 1, 8, 4) + Check(i + 1, j + 1, 8, 4);
      cnt += Check(i - 1, j + 1, 6, 2) + Check(i + 1, j - 1, 6, 2);
      if (cnt == 8) {
        mgx = i;
        mgy = j;
      }
    }
  }
  int row, column;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      b[i][j] = Check1(i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = 1; j <= m; ++j) {
      sum += b[i][j];
    }
    if (!sum) {
      row = i;
      break;
    }
  }
  for (int j = 1; j <= m; ++j) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += b[i][j];
    }
    if (!sum) {
      column = j;
      break;
    }
  }
  cout << mgx << ' ' << mgy << '\n';
  cout << row << ' ' << column << '\n';
  return 0;
}
