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
    int n; int64_t k; cin >> n >> k;
    vector<int64_t> a(n);
    for (auto &u: a) cin >> u;
    sort(a.begin(), a.end(), greater<>());
    int64_t d = a[0];
    int64_t cnt = 0, sum = accumulate(a.begin(), a.end(), 0ll);
    for (auto u: a) {
      cnt += (d - u);
    }
    int res = 1;
    for (int i = 1; i <= n; ++i) {
      int64_t cost = (i - (sum % i)) % i;
      d = (sum + cost) / i;
      if (d < a[0]) {
        int64_t ras = a[0] - d;
        d = a[0];
        cost += i * ras;
      }
      if (!(cost > k || cost > cnt + n * (d - a[0]))) {
        res = i;
      }
    }
    cout << res << '\n';
  }
}

