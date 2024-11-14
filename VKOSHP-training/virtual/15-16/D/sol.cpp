/**
 *    author:  feev1x
 *    created: 15.10.2024 10:18:46
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, t; cin >> n >> k >> t;
  vector<int64_t> z(n);
  for (auto &u: z) cin >> u;
  int64_t nw = 0;
  for (int i = 1; i <= n; ++i) {
    int64_t s; cin >> s;
    nw += z[i - 1];
    if (s > nw) {
      if (s - nw <= k) {
        nw += (s - nw) + t;
      } else {
        nw += k;
      }
    } else {
      nw += t;
    }
  }
  cout << nw << '\n';
}
