/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(k);
  map<int, bool> mp;
  for (auto &u: a) cin >> u, mp[u] = true;
  vector<vector<int>> g(n + 1);
  int64_t res = 0;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    if (mp[x] && y == n || mp[y] && x == n) res = -1;
  }
  if (res == -1) {
    cout << res << '\n';
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int cnt = g[i].size();
    cnt = n - (cnt + 1 + mp[i]);
    res += cnt;
  }
  int cnt = g[n].size();
  cnt = n - (cnt + 1 + k);
  res += cnt;
  cout << res / 2 << '\n';
}

