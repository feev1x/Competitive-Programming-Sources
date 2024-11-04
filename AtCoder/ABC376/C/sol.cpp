/**
 *    author:  feev1x
 *    created: 19.10.2024 18:29:03
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
  int n; cin >> n;
  vector<int> a(n), b(n - 1);
  for (auto &u: a) cin >> u;
  for (auto &u: b) cin >> u;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  bool flag = true;
  for (int i = 0; i < n - 1; ++i) {
    if (b[i] < a[i]) {
      flag = false;
      break;
    }
  }
  int mn = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] <= b[i]) {
      mn = a[i];
    } else {
      mn = a[i + 1];
      break;
    }
  }
  if (flag) {
    cout << mn << '\n';
  } else {
    cout << "-1\n";
  }
  return 0;
}
