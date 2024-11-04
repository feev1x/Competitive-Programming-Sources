/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int64_t x; cin >> n >> x;
  vector<int64_t> a(n), p(n), b(n), q(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> p[i] >> b[i] >> q[i];
  }
  int64_t l = 0, r = 1e9 + 7, ans = 0;
  while (l <= r) {
    int64_t m = l + r >> 1;
    int64_t cnt = 0;
    for (int i = 0; i < n; ++i) {
      int64_t opt = 1e9 + 7;
      for (int j = 0; j <= b[i]; ++j) {
        int64_t sm = j * p[i];
        int64_t md = max(int64_t(0), m - j * a[i]);
        sm += q[i] * ((md + b[i] - 1) / b[i]);
        opt = min(opt, sm);
      }
      for (int j = 0; j <= a[i]; ++j) {
        int64_t sm = j * q[i];
        int64_t md = max(int64_t(0), m - j * b[i]);
        sm += p[i] * ((md + a[i] - 1) / a[i]);
        opt = min(opt, sm);
      }
      cnt += opt;
      if (cnt > x) {
        break;
      }
    }
    if (cnt > x) {
      r = m - 1;
    } else {
      l = m + 1;
      ans = m;
    }
  }
  cout << ans << '\n';
}

