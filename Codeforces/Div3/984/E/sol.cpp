/**
 *    author:  feev1x
 *    created: 02.11.2024 21:41:29
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
  ll n, k, q; scanf("%lld%lld%lld", &n, &k, &q);
  vector a(n, vector<ll>(k)), b(n, vector<ll> (k)), v(k, vector<ll>(n));
  for (auto &u: a) {
    for (auto &v: u) {
      scanf("%lld", &v);
    }
  }
  b[0] = a[0];
  for (ll i = 1; i < n; ++i) {
    for (ll j = 0; j < k; ++j) {
      b[i][j] = a[i][j] | b[i - 1][j];
      assert(b[i][j] >= b[i - 1][j]);
    }
  }
  debug(b);
  for (ll j = 0; j < k; ++j) {
    for (ll i = 0; i < n; ++i) {
      v[j][i] = b[i][j];
    }
    assert(is_sorted(v[j].begin(), v[j].end()));
  }
  while (q--) {
    ll m; scanf("%lld", &m);
    ll l = 0, R = n - 1;
    while (m--) {
      ll r, c; char ch; scanf("%lld %c %lld", &r, &ch, &c); r--;
      debug(ch);
      if (ch == '>') {
        auto it = upper_bound(v[r].begin(), v[r].end(), c);
        ll j = it - v[r].begin();
        l = max(l, j);
      } else {
        auto it = lower_bound(v[r].begin(), v[r].end(), c);
        ll j = it - v[r].begin();
        R = min(R, j - 1);
      }
    }
    if (l > R || l >= n) {
      printf("-1\n");
    } else {
      printf("%lld\n", l + 1);
    }
  }
  return 0;
}
