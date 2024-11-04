/**
 *    author:  feev1x
 *    created: 24.10.2024 22:08:40
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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == i) continue;
      if (p[p[i]] == i) continue;
      cnt++;
      int a = p[pos[i]], b = p[p[i]];
      swap(p[pos[i]], p[p[i]]);
      swap(pos[a], pos[b]);
    }
    cout << cnt << '\n';
  }
  return 0;
}
