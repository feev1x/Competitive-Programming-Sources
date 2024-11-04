/**
 *    author:  feev1x
 *    created: 29.10.2024 14:17:27
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
  int n; cin >> n;
  vector<int> ord;
  string vl = "&|^";
  map<char, int> mp, all;
  map<char, bool> used;
  all['&'] = 1023;
  mp['&'] = 0;
  mp['|'] = 1;
  mp['^'] = 2;
  for (int i = 0; i < n; ++i) {
    char ch; cin >> ch;
    int u; cin >> u;
    if (ch == '&') {
      all['&'] &= u;
      all['|'] &= u;
      all['^'] &= u;
    } else if (ch == '|') {
      all['|'] |= u;
      all['&'] |= u;
    } else {
      all['^'] ^= u;
      all['|'] ^= u;
    }
  }
  cout << 3 << '\n';
  for (auto u: vl) {
    cout << u << ' ' << all[u] << '\n';
  }
  return 0;
}
