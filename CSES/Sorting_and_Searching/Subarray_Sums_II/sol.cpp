/**
 *    author:  feev1x
 *    created: 04.11.2024 20:43:46
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
  int n; ll x; scanf("%d%lld", &n, &x);
  vector<ll> a(n + 1), p(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    p[i] = p[i - 1] + a[i];
  }
  map<ll, int> mp;
  ll res = 0;
  for (int i = 0; i <= n; ++i) {
    res += mp[p[i] - x];
    mp[p[i]]++;
  }
  printf("%lld\n", res);
  return 0;
}
