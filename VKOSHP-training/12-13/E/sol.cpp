/**
 *    author:  feev1x
 *    created: 17.10.2024 10:59:45
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
//  freopen("jediacademy.in", "r", stdin);
//  freopen("jediacademy.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> type(n + 1), d(n + 1);
  map<int, map<int, set<int>>> mp;
  vector<set<int>> g(n + 1), e(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> type[i] >> d[i];
    mp[d[i]][type[i]].emplace(i);
    for (int j = 0; j < d[i]; ++j) {
      int u; cin >> u;
      g[i].emplace(u);
      e[u].emplace(i);
    }
  }
  int a, b; cin >> a >> b;
  auto ans = [](vector<int> type, vector<int> d, map<int, map<int, set<int>>> mp, vector<set<int>> g, vector<set<int>> e, int a, int b, int nw) {
    //st
    int cnt = 0;
st:
    cnt += a;
    while (!mp[0][nw].empty()) {
      auto it = mp[0][nw].begin();
      int v = *it;
      mp[0][nw].erase(it);
      for (auto u: e[v]) {
        g[u].erase(v);
        mp[d[u]][type[u]].erase(u);
        d[u]--;
        mp[d[u]][type[u]].emplace(u);
      }
      e[v].clear();
    }
    if (nw == 1) nw = 2;
    else nw = 1;
    if (!mp[0][nw].empty()) goto st;
    return cnt;
  };
  cout << n * b + min(ans(type, d, mp, g, e, a, b, 1), ans(type, d, mp, g, e, a, b, 2)) << '\n';
  return 0;
}
