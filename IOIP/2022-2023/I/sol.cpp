/**
 *    author:  feev1x
 *    created: 06.11.2024 11:45:56
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
  vector<int> a(n + 1), p(n + 1);
  map<int, int> chn;
  int nw = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (!chn[a[i]]) {
      chn[a[i]] = nw++;
    }
    a[i] = chn[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  vector<bool> used(n + 1);
  ll res = 1;
  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    int len = 1;
    vector<int> mp(nw, -1), fr(nw, -1), us;
    mp[a[i]] = 0;
    us.emplace_back(a[i]);
    debug(a[i], i);
    fr[a[i]] = 0;
    used[i] = true;
    int u = p[i];
    while (!used[u]) {
      used[u] = true;
      if (mp[a[u]] != -1) {
        res = max(res, ll(len) - mp[a[u]]);
      } else {
        fr[a[u]] = len;
        us.emplace_back(a[u]);
      }
      mp[a[u]] = len;
      len++;
      u = p[u];
    }
    int ind = 0;
    auto Dis = [&](int A, int B) {
      swap(A, B);
      if (A > B) return (ll)A - B;
      return (ll)len - B + A;
    };
    for (auto v: us) {
      int A = mp[v], B = fr[v];
      debug(A, B);
      res = max(res, Dis(A, B));
      debug(Dis(A, B), v);
    }
  }
  printf("%lld\n", res);
  return 0;
}
