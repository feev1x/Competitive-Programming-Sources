/**
 *    author:  feev1x
 *    created: 19.10.2024 20:05:01
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
    vector<int> a(n);
    for (auto &u: a) cin >> u;
    sort(a.begin(), a.end());
    cout << (a.back() - a.front()) * (n - 1) << '\n';
  }
  return 0;
}
