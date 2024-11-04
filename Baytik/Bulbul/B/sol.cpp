/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t; cin >> n >> t;
  vector<int> a(n);
  for (auto &u: a) cin >> u, u %= t;
  sort(a.begin(), a.end());
  int mn = abs(a[0] - a[n - 1]);
  for (int i = 1; i < n; ++i) mn = min(mn, t - (a[i] - a[i - 1]));
  cout << (mn + 1) / 2;
}

