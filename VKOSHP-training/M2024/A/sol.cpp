/**
 *    author:  feev1x
 *    created: 05.11.2024 12:09:51
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
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<ll> a(n + 1), p(n + 1), dp(n + 1, 1e18);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (i) g[i].emplace_back(i - 1, 0);
      if (i < b[i]) g[i].emplace_back(b[i], a[i]);
    }
    set<pair<ll, int>> q;
    dp[1] = 0;
    q.emplace(dp[1], 1);
    while (!q.empty()) {
      auto [sm, cur] = *q.begin();
      q.erase(q.begin());
      for (auto [to, w]: g[cur]) {
        if (dp[to] > dp[cur] + w) {
          q.erase({dp[to], to});
          dp[to] = dp[cur] + w;
          q.emplace(dp[to], to);
        }
      }
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = p[i] - dp[i];
    }
    printf("%lld\n", *max_element(dp.begin(), dp.end()));
  }
  return 0;
}

