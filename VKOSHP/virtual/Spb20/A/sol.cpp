/**
 *    author:  feev1x
 *    created: 08.11.2024 13:07:28
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
  vector<ll> l(n);
  int sum = 0;
  for (auto &u: l) {
    scanf("%lld", &u);
    sum += u;
  }
  vector<bool> used(sum + 1);
  used[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = sum; j >= l[i]; --j) {
      if (used[j - l[i]]) used[j] = true;
    }
  }
  ll res = 0, cnt = 0;
  for (int i = 0; i <= sum; ++i) {
    if (used[i]) {
      res += sum - i + 1;
      cnt++;
    } else res += cnt;
  }
  printf("%lld\n", res);
  return 0;
}
