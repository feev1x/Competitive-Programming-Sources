/**
 *    author:  feev1x
 *    created: 29.10.2024 08:45:53
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
  int n; double b; cin >> n >> b;
  vector<double> a(n);
  double sum = b, mx = 0;
  for (auto &u: a) cin >> u, mx = max(mx, u), sum += u;
  if (sum / n < mx) {
    cout << "-1\n";
    return 0;
  }
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; ++i) {
    cout << (sum / n) - a[i] << '\n';
  }
  return 0;
}
