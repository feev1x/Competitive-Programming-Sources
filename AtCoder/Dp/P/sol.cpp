/**
 *    author:  feev1x
 *    created: 18.10.2024 08:13:00
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto Modp = [](int64_t &a, int64_t b) {
    int64_t mod = 1e9 + 7;
    return a = (a + b) % mod;
  };
  auto Modm = [](int64_t &a, int64_t b) {
    int64_t mod = 1e9 + 7;
    return a = (a * b) % mod;
  };
  int n; cin >> n;
  vector<vector<int>> g(n + 1);
  vector<array<int64_t, 2>> dp(n + 1, {1, 1});
  // 0 - black, 1 - white
  for (int i = 1; i < n; ++i) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  function<void(int, int)> Dfs = [&](int v, int p) {
    for (auto to: g[v]) {
      if (to == p) continue;
      Dfs(to, v);
      Modm(dp[v][0], dp[to][1]);
      Modm(dp[v][1], Modp(dp[to][0], dp[to][1]));
    }
  };
  Dfs(1, -1);
  cout << Modp(dp[1][0], dp[1][1]) << '\n';
  return 0;
}
