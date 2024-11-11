/**
 *    author:  feev1x
 *    created: 09.11.2024 18:06:08
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
  int n, m; scanf("%d%d", &n, &m);
  vector<ll> x(m), a(m);
  vector<pair<ll, ll>> suka;
  for (auto &u: x) {
    scanf("%lld", &u);
  }
  ll sum = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%lld", &a[i]);
    sum += a[i];
    suka.emplace_back(x[i], a[i]);
  }
  sort(suka.begin(), suka.end());
  for (int i = 0; i < m; ++i) {
    tie(x[i], a[i]) = suka[i];
  }
  if (sum != n) {
    printf("-1\n");
    return 0;
  }
  if (x[0] != 1) {
    printf("-1\n");
    return 0;
  }
  ll gr = 1;
  ll res = 0;
  for (int i = 0; i < m; ++i) {
    ll nx = (i == m - 1 ? n : x[i + 1]);
    if (x[i] == n) {
      break;
    }
    if (a[i] - 1 < nx - x[i] - 1) {
      printf("-1\n");
      return 0;
    }
    gr = nx;
    res += (nx - x[i]) * (nx - x[i] - 1) / 2;
    a[i] -= (nx - x[i] - 1);
    res += (a[i] - 1) * (nx - x[i]);
    if (i != m - 1) {
      a[i + 1] += a[i] - 1;
    }
  }
  printf("%lld\n", res);
  return 0;
}
