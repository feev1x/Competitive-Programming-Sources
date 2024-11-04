/**
 *    author:  feev1x
 *    created: 24.10.2024 22:20:46
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
    vector<int> a(n), p(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      p[i + 1] = a[i] + p[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      map<int, bool> mp;
      mp[p[i - 1]] = true;
      while (i <= n) {
        if (mp[p[i]]) {
          cnt++;
          break;
        }
        mp[p[i]] = true;
        i++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
