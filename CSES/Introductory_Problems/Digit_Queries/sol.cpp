/**
 *    author:  feev1x
 *    created: 05.11.2024 16:47:43
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

ll binpow(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
  return res;
}

signed main() {
  int q; scanf("%d", &q);
  while (q--) {
    ll k; scanf("%lld", &k);
    ll pos = 0, val = 0, sz = 1;
    while (pos < k) {
      pos += (binpow(10ll, sz) - binpow(10ll, sz - 1)) * sz++;
    }
    sz--;
    pos -= (binpow(10ll, sz) - binpow(10ll, sz - 1)) * sz;
    ll num = (k - pos + sz - 1) / sz;
    ll ind = num * sz + pos - k;
    ind = sz - ind - 1;
    num = binpow(10ll, sz - 1) + num - 1;
    string s = to_string(num);
    printf("%c\n", s[ind]);
  }
  return 0;
}
