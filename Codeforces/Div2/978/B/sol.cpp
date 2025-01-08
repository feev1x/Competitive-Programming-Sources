/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, x; cin >> n >> x;
    int64_t sm = 0;
    int64_t mx = 0;
    vector<int64_t> a(n);
    for (auto &u: a) {
      cin >> u;
      sm += u;
      mx = max(u, mx);
    }
    int64_t res = sm;
    int64_t l = mx, r = sm, ans = 0;
    while (l <= r) {
      int64_t m = l + r >> 1;
      if (sm / m + (sm % m > 0) > x) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    cout << ans << '\n';
  }
}

