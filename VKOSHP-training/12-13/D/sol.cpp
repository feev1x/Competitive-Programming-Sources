/**
 *    author:  feev1x
 *    created: 17.10.2024 17:10:19
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
//  freopen("forest.in", "r", stdin);
//  freopen("forest.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int dx[] = {1, -1, 0, 0, 0};
  int dy[] = {0, 0, 1, -1, 0};
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  set<pair<int, int>> st1, st2;
  for (auto &u: a) {
    for (auto &v: u) {
      cin >> v;
    }
  }
  auto Check = [&](int i, int j) {
    if (!(0 <= i && i < n && 0 <= j && j < m)) return false;
    for (int k = 0; k < 5; ++k) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (0 <= x && x < n && 0 <= y && y < m && a[x][y] - a[i][j] == 1) {
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (Check(i, j)) {
        st1.emplace(i, j);
      }
    }
  }
  for (auto [i, j]: st1) {
    a[i][j]++;
  }
  int res = 0;
  while (!st1.empty()) {
    while (!st1.empty()) {
      auto [i, j] = *st1.begin();
      st1.erase(st1.begin());
      for (int k = 0; k < 5; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (Check(x, y)) {
          st2.emplace(x, y);
        }
      }
    }
    for (auto [i, j]: st2) {
      a[i][j]++;
    }
    st1 = st2;
    st2.clear();
    res++;
  }
  cout << res << '\n';
  for (auto u: a) {
    for (auto v: u) {
      cout << v << ' ';
    }
    cout << '\n';
  }
  return 0;
}
