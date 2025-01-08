/**
 *    author:  feev1x
 *    created: 16.10.2024 21:09:22
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, x; cin >> n >> x;
    vector<int64_t> b(n);
    for (auto &u: b) cin >> u;
    if (n == 1) {
      cout << 0 << '\n' << b[0] << '\n';
      continue;
    }
    sort(b.begin(), b.end());
    vector<int64_t> c(n);
    int64_t l = 0, r = 2e9, ans = 0;
    while (l <= r) {
      int64_t m = l + r >> 1;
      vector<int64_t> b1 = b;
      bool flag = true;
      b[0] += m;
      for (int i = 1; i < n; ++i) {
        if (b[i] < b[i - 1]) {
          b[i - 1] = b[i];
        }
        int did = 0;
        if (b[i] - b[i - 1] > x) {
          b[i] = b[i - 1] + x;
          did = 1;
          if (abs(b1[i] - (b[i - 1] + x)) > m) {
            flag = false;
            break;
          }
        }
        if (did) {
          // nothing
        } else {
          b[i] = min(b[i - 1] + x, b[i] + m);
        }
      }
      if (flag) {
        r = m - 1;
        ans = m;
        c = b;
        b = b1;
      } else {
        b = b1;
        flag = true;
        b[n - 1] -= m;
        for (int i = n - 1; i > 0; --i) {
          if (b[i] < b[i - 1]) {
            b[i] = b[i - 1];
          }
          int did = 0;
          if (b[i] - b[i - 1] > x) {
            b[i - 1] = b[i] - x;
            did = 1;
            if (abs(b1[i - 1] - (b[i] - x)) > m) {
              flag = false;
              break;
            }
          }
          if (did) {
            // nothing
          } else {
            b[i - 1] = max(b[i] - x, b[i - 1] - m);
          }
        }
        if (flag) {
          r = m - 1;
          ans = m;
          c = b;
          b = b1;
        } else {
          l = m + 1;
          b = b1;
        }
      }
    }
    cout << ans << '\n';
    for (auto u: c) cout << u << ' ';
    cout << '\n';
  }
  return 0;
}
