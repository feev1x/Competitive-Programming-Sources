/**
 *    author:  feev1x
 *    created: 24.10.2024 09:05:08
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int64_t mod = (1ll << 32ll);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int64_t n, l, r, x, y, z, b1, b2; cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    int64_t mn = 1e18, res = 1e18;
    int64_t bi2 = b1, bi1 = b2;
    int64_t a1 = (b1 % (r - l + 1)) + l;
    int64_t a2 = (b2 % (r - l + 1)) + l;
    mn = min(a1, a2);
    res = (a1 < a2 ? a1 * a2 : 1e18);
    for (int i = 3; i <= n; ++i) {
      int64_t bi = (bi2 * x + bi1 * y + z) % mod;
      bi2 = bi1;
      bi1 = bi;
      int64_t ai = (bi % (r - l + 1)) + l;
      if (mn < ai) {
        res = min(res, ai * mn);
      } else if (mn > ai) {
        mn = ai;
      }
    }
    if (res == 1e18) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res << '\n';
    }
  }
  return 0;
}
