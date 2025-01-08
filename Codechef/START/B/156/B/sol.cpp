/**
 *    author:  feev1x
 *    created: 16.10.2024 20:34:21
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &u: a) cin >> u;
    sort(a.begin(), a.end());
    if (k == 1) {
      cout << a[n - 1] * 2 + a[0] + a[n - 2] << '\n';
      continue;
    }
    cout << a[n - 1] + a[0] + a[n - 2] + a[n - k - 1] << '\n';
  }
  return 0;
}
