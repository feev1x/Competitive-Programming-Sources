/**
 *    author:  feev1x
 *    created: 24.10.2024 15:03:33
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
  int64_t t, n, a, b, k; cin >> t >> n >> a >> b >> k;
  if (k > n) {
    cout << 0 << '\n';
    return 0;
  }
  int64_t l = 1, r = t, ans = 0;
  while (l <= r) {
    int64_t m = l + r >> 1;
    int64_t ch_a = min(a, m);
    int64_t ch_b = min(b, m);
    int64_t total = ((n + 1) / 2) * ch_a + (n / 2) * ch_b;
    if (total / m >= k) {
      l = m + 1;
      ans = m;
    } else {
      r = m - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
