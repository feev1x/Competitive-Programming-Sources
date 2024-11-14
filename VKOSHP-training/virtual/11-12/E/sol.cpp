/**
 *    author:  feev1x
 *    created: 16.10.2024 09:45:31
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

bool check(vector<int> a) {
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] <= a[i - 1]) {
      return false;
    }
  }
  return true;
}

signed main() {
  freopen("parade.in", "r", stdin);
  freopen("parade.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  a.insert(a.begin(), 0);
  vector<int64_t> d(n + 3, 1e18), pos(n + 1, -1), ls(n + 1, -1);
  vector<bool> used(n + 1);
  int lst = -1;
  d[0] = -1e18;
  for (int i = 1; i <= n; ++i) {
    int j = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    d[j] = a[i];
    if (d[j + 1] == 1e18) {
      pos[j] = i;
      ls[i] = pos[j - 1];
      lst = i;
    }
  }
  vector<int> rs;
  for (int v = lst; v != -1; v = ls[v]) {
    rs.emplace_back(v);
    used[v] = true;
  }
  reverse(rs.begin(), rs.end());
  vector<int> ost;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) ost.emplace_back(a[i]);
  }
  reverse(ost.begin(), ost.end());
  if (!check(ost)) {
    cout << "Impossible\n";
    return 0;
  }
  cout << rs.size() << '\n';
  for (auto u: rs) cout << u << ' ';
  cout << '\n';
}
