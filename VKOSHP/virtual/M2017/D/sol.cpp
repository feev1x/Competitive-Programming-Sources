/**
 *    author:  feev1x
 *    created: 21.10.2024 17:47:51
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
  vector<vector<int>> s(n + 1);
  vector<int> k(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    int l; cin >> l;
    s[i].assign(l + 1, 0);
    for (int j = 1; j <= l; ++j) {
      cin >> s[i][j];
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < min(s[i].size(), s[i - 1].size()); ++j) {
      if (s[i][j] != s[i - 1][j]) {
        k[i - 1] = j;
        break;
      }
    }
  }
  vector<vector<int>> g(m + 1);
  vector<bool> cap(m + 1);
  vector<int> ans;
  auto Add = [&](int v) {
    if (!cap[v]) {
      ans.emplace_back(v);
    }
  };
  for (int i = 1; i < n; ++i) {
    if (k[i] == -1) continue;
    if (s[i][k[i]] > s[i + 1][k[i]]) {
      Add(s[i][k[i]]);
      cap[s[i][k[i]]] = true;
    } else {
      g[s[i + 1][k[i]]].emplace_back(s[i][k[i]]);
    }
  }
  for (int i = m; i >= 1; --i) {
    if (cap[i]) {
      for (auto to: g[i]) {
        Add(to);
        cap[to] = true;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < s[i].size(); ++j) {
      if (cap[s[i][j]]) {
        s[i][j] -= m;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] > s[i + 1]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}
