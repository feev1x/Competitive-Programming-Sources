/**
 *    author:  feev1x
 *    created: 17.10.2024 09:54:37
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
//  freopen("billboard.in", "r", stdin);
//  freopen("billboard.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, n, m; cin >> k >> n >> m;
  vector<vector<string>> ie(k, vector<string>(n));
  vector<set<pair<int, int>>> gr(1);
  vector<vector<int>> fg(n, vector<int>(m));
  for (int _ = 0; _ < k; ++_) {
    int sz = gr.size();
    vector<set<pair<int, int>>> ngr(gr.size() * 2);
    for (int i = 0; i < n; ++i) {
      cin >> ie[_][i];
      for (int j = 0; j < m; ++j) {
        if (ie[_][i][j] == '.') {
          ngr[fg[i][j]].emplace(i, j);
        } else {
          ngr[fg[i][j] + sz].emplace(i, j);
        }
      }
    }
    gr.clear();
    for (int i = 0; i < ngr.size(); ++i) {
      if (ngr[i].empty()) continue;
      gr.emplace_back(ngr[i]);
    }
    for (int i = 0; i < gr.size(); ++i) {
      for (auto [u, v]: gr[i]) {
        fg[u][v] = i;
      }
    }
  }
  cout << gr.size() << '\n';
  return 0;
}
