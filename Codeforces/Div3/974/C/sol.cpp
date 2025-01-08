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
    int n; cin >> n;
    vector<int64_t> a(n);
    for (auto &u: a) cin >> u;
    int j = (max_element(a.begin(), a.end()) - a.begin());
    int64_t l = 0, r = 1e18, ans = -1;
    while (l <= r) {
      int64_t m = l + r >> 1;
      long double sum = 0;
      a[j] += m;
      for (auto u: a) sum += u;
      sum /= n;
      int64_t cnt = 0;
      for (auto u: a) cnt += (u < sum / 2.);
      a[j] -= m;
      if (cnt > n / 2) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ans << '\n';
  }
}

