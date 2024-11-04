/**
 *    author:  feev1x
 *    created: 26.10.2024 18:05:15
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
  int64_t n, m; cin >> n >> m;
  int64_t res = n * n;
  map<int, map<int, bool>> mp;
  int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
  auto Check = [&](int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= n;
  };
  while (m--) {
    int a, b; cin >> a >> b;
    if (!mp[a][b]) {
      res--;
      mp[a][b] = true;
    }
    for (int k = 0; k < 8; ++k) {
      int x = a + dx[k];
      int y = b + dy[k];
      if (Check(x, y) && !mp[x][y]) {
        res--;
        mp[x][y] = true;
      }
    }
  }
  cout << res << '\n';
  return 0;
}
