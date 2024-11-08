/**
 *    author:  feev1x
 *    created: 07.11.2024 16:20:51
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
  int n, q; scanf("%d%d", &n, &q);
  vector<pair<ll, ll>> pc(n);
  for (auto &[p, c]: pc) {
    scanf("%lld%lld", &p, &c);
  }
  sort(pc.begin(), pc.end());
  vector<ll> p(n), c(n), pref(n);
  for (int i = 0; i < n; ++i) {
    p[i] = pc[i].first;
    c[i] = pc[i].second;
  }
  int zr = -1;
  ll nw = 1;
  for (int i = 0; i < n; ++i) {
    if (nw >= p[i]) {
      nw += p[i];
      zr = i;
    } else {
      break;
    }
  }
  pref[0] = p[0] + 1;
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + p[i];
  }
  for (int i = n - 2; i >= 0; --i) {
    if (pref[i] >= p[i + 1]) {
      pref[i] = pref[i + 1];
    }
  }
  vector<ll> suf(n);
  suf[n - 1] = c[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = min(suf[i + 1], c[i]);
  }
  debug(pref, suf);
  while (q--) {
    ll x; scanf("%lld", &x);
    int j = lower_bound(pref.begin(), pref.end(), x) - pref.begin();
    if (zr >= j || x == 1) {
      printf("0 ");
    } else if (j == n) {
      printf("-1 ");
    } else {
      printf("%lld ", suf[j]);
    }
  }
  printf("\n");
  return 0;
}
