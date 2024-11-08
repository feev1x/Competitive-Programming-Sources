/**
 *    author:  feev1x
 *    created: 07.11.2024 22:29:50
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int n; scanf("%d", &n);
  vector<ll> a(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  vector<ll> ans(121);
  vector<array<ll, 65>> left(n), right(n);
  for (int i = 0; i < n; ++i) {
    left[i][0] = 0;
    right[i][0] = 0;
    for (int sz = 1; sz <= min(60, n - 1); ++sz) {
      ll val = 0;
      for (int j = ((i - sz) % n + n) % n; j != i; j = (j + 1) % n) {
        val += a[j];
        val /= 2;
      }
      left[i][sz] = max(left[i][sz - 1], val);
      val = 0;
      for (int j = (i + sz) % n; j != i; j = ((j - 1) % n + n)% n) {
        val += a[j];
        val /= 2;
      }
      right[i][sz] = max(right[i][sz - 1], val);
    }
    for (int sz = min(60, n - 1) + 1; sz < 65; ++sz) {
      left[i][sz] = right[i][sz] = 0;
    }
  }
  ans[0] = *max_element(a.begin(), a.end());
  for (int sz = 1; sz <= 120; ++sz) {
    if (sz >= n) {
      ans[sz] = ans[sz - 1];
      continue;
    }
    debug(sz, n);
    for (int i = 0; i < n; ++i) {
      for (int l = 0; l <= sz; ++l) {
        int r = sz - l;
        if (l > 60 || r > 60) {
          continue;
        }
        if (sz == n - 1) {
          if (r + 1 <= sz) {
            ans[sz] = max(ans[sz], left[i][l] + right[i][r + 1] + a[i]);
          }
          if (l + 1 <= sz) {
            ans[sz] = max(ans[sz], left[i][l + 1] + right[i][r] + a[i]);
          }
        } else {
          ans[sz] = max(ans[sz], left[i][l] + right[i][r] + a[i]);
        }
        debug(sz, l, r, i, left[i][l], right[i][r]);
      }
    }
  }
  int q; scanf("%d", &q);
  while (q--) {
    int t; scanf("%d", &t);
    t = min(t, 120);
    printf("%lld\n", ans[t]);
  }
  return 0;
}
