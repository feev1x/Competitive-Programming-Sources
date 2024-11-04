/**
 *    author:  feev1x
 *    created: 21.10.2024 09:06:00
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
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  vector<int64_t> mp(28);
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < 28; ++j) {
      if (a[i] & (1ll << j)) {
        mp[j]++;
      }
    }
  }
  int64_t res = 0;
  for (int64_t j = 0; j < 28; ++j) {
    res += (1ll << j) * (mp[j] * (mp[j] - 1) / 2);
  }
  cout << res << '\n';
  return 0;
}
