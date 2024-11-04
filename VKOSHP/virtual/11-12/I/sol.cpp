/**
 *    author:  feev1x
 *    created: 16.10.2024 16:04:19
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
  freopen("teams.in", "r", stdin);
  freopen("teams.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(2 * n + 1);
  vector<array<int, 2>> pos(n + 1);
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> a[i];
    if (pos[a[i]][0]) {
      pos[a[i]][1] = i;
    } else {
      pos[a[i]][0] = i;
    }
  }
  vector<bool> used(n + 1);
  vector<pair<int, int>> opt(n + 1);
  for (int i = 1; i <= n; ++i) {
    opt[i].first = pos[i][1] - n;
    opt[i].second = i;
  }
  sort(opt.begin() + 1, opt.end());
  vector<int> ans;
  for (int i = 1; i <= n; ++i) {
    if (!used[a[i]]) {
      used[a[i]] = true;
      ans.emplace_back(a[i]);
    } else {
      for (int j = 1; j <= n; ++j) {
        if (!used[opt[j].second]) {
          used[opt[j].second] = true;
          ans.emplace_back(opt[j].second);
          break;
        }
      }
    }
  }
  for (auto u: ans) cout << u << ' ';
  for (auto u: ans) cout << u << ' ';
  cout << '\n';
}
