/**
 *    author:  feev1x
 *    created: 07.11.2024 10:32:27
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
  vector<pair<ll, int>> sum(10);
  vector<bool> used(10);
  for (int i = 0; i < n; ++i) {
    ll u; scanf("%lld", &u);
    ll um = 1;
    while (u > 0) {
      if (u / 10 == 0) {
        used[u % 10] = true;
      }
      sum[u % 10].first += um;
      um *= 10;
      u /= 10;
    }
  }
  for (int i = 0; i < 10; ++i) {
    sum[i].second = i;
  }
  sort(sum.begin(), sum.end());
  if (used[sum[0].second]) {
    for (int i = 1; i < 10; ++i) {
      if (!used[sum[i].second]) {
        swap(sum[0], sum[i]);
        break;
      }
    }
  }
  sort(sum.begin() + 1, sum.end());
  ll res = 0;
  for (int i = 9; i >= 1; --i) {
    res += sum[i].first * i;
  }
  printf("%lld\n", res);
  return 0;
}
