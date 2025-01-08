/**
 *    author:  feev1x
 *    created: 31.10.2024 20:52:12
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

inline void mul_self(int &a, int b, int m) {
  a = (ll) a * b % m;
}

signed main() {
  int n; ll k; scanf("%d%lld", &n, &k);
  vector<int> p(n + 1), ans(n + 1), pos(n + 1);
  vector<bool> used(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (used[p[i]]) {
      continue;
    }
    vector<int> cyc;
    int u = p[p[i]];
    cyc.emplace_back(p[i]);
    used[p[i]] = true;
    while (u != p[i]) {
      used[u] = true;
      cyc.emplace_back(u);
      u = p[u];
      debug(cyc);
    }
    int len = cyc.size();
    auto Binpow = [&](int a, ll b) {
      int res = 1;
      while (b) {
        if (b & 1) {
          mul_self(res, a, len);
        }
        mul_self(a, a, len);
        b >>= 1ll;
      }
      return res;
    };
    int K = Binpow(2, k);
    for (int j = 0; j < len; ++j) {
      ans[cyc[j]] = cyc[(j + K) % len];
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}
