/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> k(n);
  for (auto &u: k) cin >> u;
  int64_t res = 1e18;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int64_t a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        a += k[i];
      } else {
        b += k[i];
      }
    }
    res = min(res, max(a, b));
  }
  cout << res << '\n';
}

