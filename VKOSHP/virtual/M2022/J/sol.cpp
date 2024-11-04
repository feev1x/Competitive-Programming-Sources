/**
 *    author:  feev1x
 *    created: 18.10.2024 11:51:26
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<int> dep(n + 1);
    vector<int> cnt(n + 1);
    vector<array<pair<int, int>, 3>> mx(n + 1);
    dep[0] = -1;
    function<int(int, int)> Dfs = [&](int v, int p) {
      dep[v] = dep[p] + 1;
      for (int i = 0; i < 3; ++i) {
        mx[v][i] = {-1, -1};
      }
      vector<pair<int, int>> ms;
      ms.emplace_back(0, v);
      for (auto to: g[v]) {
        if (to == p) continue;
        ms.emplace_back(Dfs(to, v) - dep[v], to);
      }
      sort(ms.begin(), ms.end(), greater<>());
      for (int i = 0; i < min(size_t(3), ms.size()); ++i) {
        mx[v][i] = ms[i];
      }
      return mx[v][0].first + dep[v];
    };
    Dfs(1, 0);
    Dfs = [&](int v, int p) {
      vector<pair<int, int>> ms;
      if (v == 1) goto hend;
      for (int i = 0; i < 3; ++i) {
        ms.emplace_back(mx[v][i]);
      }
      if (mx[p][0].second == v) {
        ms.emplace_back(mx[p][1].first + 1, p);
      } else {
        ms.emplace_back(mx[p][0].first + 1, p);
      }
      sort(ms.begin(), ms.end(), greater<>());
      for (int i = 0; i < 3; ++i) {
        mx[v][i] = ms[i];
      }
hend:
      for (auto to: g[v]) {
        if (to == p) continue;
        Dfs(to, v);
      }
      return 0;
    };
    Dfs(1, 0);
    int cost = 0;
    int nd = 0;
    Dfs = [&](int v, int p) {
      if (cost >= nd) return v;
      cost++;
      if (mx[v][0].second == p) {
        return Dfs(mx[v][1].second, v);
      }
      return Dfs(mx[v][0].second, v);
    };
    for (int i = 1; i <= n; ++i) {
      int l1 = mx[i][0].first;
      int l2 = mx[i][1].first;
      int l3 = mx[i][2].first;
      if (l1 >= 3 && l2 >= 2 && l3 >= 1) {
        nd = 3;
        cout << "Yes\n";
        for (int j = 0; j < 3; ++j) {
          cost = 1;
          cout << Dfs(mx[i][j].second, i) << " \n"[j == 2];
          nd--;
        }
        goto finish;
      }
    }
    cout << "No\n";
finish:
    continue;
  }
  return 0;
}
