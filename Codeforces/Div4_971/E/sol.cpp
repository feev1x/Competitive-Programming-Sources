/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

int64_t sum(int64_t a, int64_t b) {
  return (b * (b + 1) - a * (a - 1)) / 2;
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    int64_t s = sum(k, k + n - 1);
    int64_t l = k, r = k + n - 1, ans = 1e18;
    while (l <= r) {
      int64_t m = l + r >> 1;
      int64_t sm1 = sum(k, m);
      int64_t sm2 = s - sm1;
      ans = min(ans, abs(sm1 - sm2));
      if (sm1 > sm2) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ans << '\n';
  }
}

