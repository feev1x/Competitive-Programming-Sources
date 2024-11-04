/**
 *    author:  feev1x
 *    created: 29.10.2024 14:10:29
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
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  int64_t mn = 2e15, cnt = 1;
  sort(a.begin(), a.end());
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] - a[i] < mn) {
      mn = a[i + 1] - a[i];
      cnt = 1;
    } else if (a[i + 1] - a[i] == mn) {
      cnt++;
    }
  }
  cout << mn << ' ' << cnt << '\n';
  return 0;
}
