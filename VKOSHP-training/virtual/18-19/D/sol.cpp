/**
 *    author:  feev1x
 *    created: 24.10.2024 09:23:24
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  vector<bool> used(n + 1);
  vector<pair<int, int>> de;
  for (int v = 1; v <= n; ++v) {
    de.emplace_back(g[v].size(), v);
  }
  sort(de.begin(), de.end());
  int ver = de.front().second;
  int ver1 = -1;
  used[ver] = true;
  for (auto to: g[ver]) {
    used[to] = true; 
  }
  bool flag = false;
  for (int v = 1; v <= n; ++v) {
    if (!used[v]) {
      ver1 = v;
      flag = true;
      break;
    }
  }
  if (!flag) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> a1(n + 1), a2(n + 1);
  int l1 = 1, r1 = n, l2 = 1, r2 = n;
  a1[ver] = r1--;
  a1[ver1] = r1--;
  a2[ver] = a2[ver1] = r2--;
  used[ver1] = true;
  for (auto to: g[ver]) {
    a1[to] = r1--;
    a2[to] = r2--;
  }
  function<void(int)> Dfs = [&](int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto to: g[v]) {
      if (used[to]) continue;
      Dfs(to);
    }
    assert(l1 <= r1 && l2 <= r2);
    a1[v] = l1++;
    a2[v] = l2++;
  };
  for (auto to: g[ver1]) {
    Dfs(to);
  }
  for (int v = 1; v <= n; ++v) {
    if (!used[v])
      Dfs(v);
  }
  for (int i = 1; i <= n; ++i) {
    cout << a1[i] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << a2[i] << ' ';
  }
  cout << '\n';
  return 0;
}
