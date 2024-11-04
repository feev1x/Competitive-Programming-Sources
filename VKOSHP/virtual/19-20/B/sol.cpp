/**
 *    author:  feev1x
 *    created: 25.10.2024 09:07:33
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
  int n, m, s; cin >> n >> m >> s;
  vector<vector<int>> a(m + 1);
  for (int i = 0; i < n; ++i) {
    int cnt, from, to; cin >> cnt >> from >> to;
    if (cnt < 0) {
      a[from].emplace_back(cnt);
    } else {
      a[to].emplace_back(cnt);
    }
  }
  bool flag = false;
  for (int i = 1; i <= m; ++i) { 
    sort(a[i].begin(), a[i].end());
    for (int j = 0; j < a[i].size(); ++j) {
      s += a[i][j];
      if (s < 0) {
        flag = true;
      }
    }
  }
  cout << (flag ? "YES" : "NO") << '\n';
  return 0;
}
