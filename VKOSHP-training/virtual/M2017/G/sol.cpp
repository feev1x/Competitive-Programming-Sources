/**
 *    author:  feev1x
 *    created: 21.10.2024 11:38:37
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n; cin >> n;
  string s; cin >> s;
  vector<int> ind;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') {
      ind.emplace_back(i);
    }
  }
  vector<int64_t> dp(n);
  vector<int64_t> a(n + 2);
  int ls = -1;
  int r = 0, b = 0;
  int64_t nw = 1;
  for (auto i: ind) {
    int64_t cnt = 1;
    if (ls != -1) cnt = dp[ls];
    if (n & 1) {
      if (i & 1) {
        if (s[i] == 'b') {
          int64_t mnb = i + 1 + (n - i) / 2;
          a[0] += nw;
          a[n - mnb + 1] -= nw;
          debug(mnb, s[i], i);
          cnt *= (n - mnb + 1);
        } else {
          int64_t mna = ((n - i) / 2);
          int64_t all = (n - mna + 1);
          a[mna] += nw;
          a[n + 1] -= nw;
          debug(mna, s[i], i);
          cnt *= all;
        }
      } else {
        if (s[i] == 'b') {
          int64_t mnb = (((n - 1) - i) / 2) + 1;
          cnt *= (n - mnb + 1);
          a[0] += nw;
          a[n - mnb + 1] -= nw;
          debug(mnb, s[i], i);
        } else {
          int64_t mna = i + 1 + (n - i) / 2;
          a[mna] += nw;
          a[n + 1] -= nw;
          debug(mna, s[i], i);
          cnt *= (n - mna + 1);
        }
      }
    } else {
      if (!(i & 1)) {
        if (s[i] == 'b') {
          int64_t mnb = i + 1 + (n - i) / 2;
          a[0] += nw;
          a[n - mnb + 1] -= nw;
          debug(mnb, s[i], i);
          cnt *= (n - mnb + 1);
        } else {
          int64_t mna = ((n - i) / 2);
          int64_t all = (n - mna + 1);
          a[mna] += nw;
          a[n + 1] -= nw;
          debug(mna, s[i], i);
          cnt *= all;
        }
      } else {
        if (s[i] == 'b') {
          int64_t mnb = (((n - 1) - i) / 2) + 1;
          cnt *= (n - mnb + 1);
          a[0] += nw;
          a[n - mnb + 1] -= nw;
          debug(mnb, s[i], i);
        } else {
          int64_t mna = i + 1 + (n - i) / 2;
          a[mna] += nw;
          a[n + 1] -= nw;
          debug(mna, s[i], i);
          cnt *= (n - mna + 1);
        }
      }
    }
    dp[i] = cnt;
    nw++;
  }
  nw = (nw * (nw - 1)) / 2;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
    if (a[i] >= nw) {
      res++;
    }
    debug(a[i], nw);
  }
  if (a[0] >= nw) {
    res++;
  }
  debug(a[0], nw);
  cout << res << '\n';
  return 0;
}
