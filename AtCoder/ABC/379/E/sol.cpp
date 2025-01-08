/**
 *    author:  feev1x
 *    created: 09.11.2024 19:10:00
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
  char S[n + 1]; scanf("%s", S);
  string s = " ";
  for (int i = 0; i < n; ++i) {
    s += S[i];
  }
  vector<ll> res, a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = (s[i] - '0') * i + a[i - 1];
  }
  ll rem = 0;
  for (int i = n; i >= 1; --i) {
    ll num = a[i];
    num += rem;
    res.emplace_back(num % 10);
    rem = num / 10;
    debug(rem, num, a[n - i + 1]);
  }
  while (rem > 0) {
    res.emplace_back(rem % 10);
    rem /= 10;
  }
  while (res.back() == 0) res.pop_back();
  reverse(res.begin(), res.end());
  for (auto u: res) printf("%lld", u);
  printf("\n");
  return 0;
}



