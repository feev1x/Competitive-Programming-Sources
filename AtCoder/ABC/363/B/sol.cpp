/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t, p; cin >> n >> t >> p;
  vector<int> a(n);
  int cnt = 0;
  for (auto &u: a) cin >> u;
  sort(a.begin(), a.end(), greater<>());
  cout << max(0, t - a[p - 1]) << '\n';
}

