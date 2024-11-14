/**
 *    author:  feev1x
 *    created: 22.10.2024 09:03:09
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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  sort(a.begin(), a.end());
  int me = 0;
  vector<pair<int, int>> mex;
  vector<int64_t> p;
  for (int i = 0; i < n; ++i) {
    if (a[i] > me) {
      mex.emplace_back(me, a[i] - 1);
      if (!p.empty()) {
        p.emplace_back(p.back() + ((a[i] - 1) - me) + 1);
      } else {
        p.emplace_back(((a[i] - 1) - me) + 1);
      }
      me = a[i] + 1;
    } else {
      me++;
    }
  }
  mex.emplace_back(a.back() + 1, 2e9);
  if (!p.empty()) {
    p.emplace_back(p.back() + (2e9 - (a.back() + 1)) + 1);
  } else {
    p.emplace_back((2e9 - (a.back() + 1)) + 1);
  }
  while (q--) {
    int k; cin >> k;
    int j = int(upper_bound(p.begin(), p.end(), k - 1) - p.begin());
    int res = mex[j].second;
    res -= (p[j] - k);
    cout << res << ' ';
  }
  return 0;
}
