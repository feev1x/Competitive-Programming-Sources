/**
 *    author:  feev1x
 *    created: 18.10.2024 07:44:27
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto Modp = [&](int64_t &a, int64_t b) {
    a = (a + b) % mod;
  };
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int64_t>> dp((1 << n), vector<int64_t>(n + 1));
  queue<pair<int, int>> q;
  vector<bool> used((1 << n));
  q.emplace(0, 0);
  dp[0][0] = 1;
  while (!q.empty()) {
    auto [mask, cur] = q.front();
    q.pop();
    if (cur == n) break;
    for (int i = 0; i < n; ++i) {
      if ((mask & (1 << i)) || !a[cur][i]) {
        continue;
      }
      Modp(dp[mask ^ (1 << i)][cur + 1], dp[mask][cur]);
      if (!used[mask ^ (1 << i)]) {
        q.emplace(mask ^ (1 << i), cur + 1);
        used[mask ^ (1 << i)] = true;
      }
    }
  }
  int all = (1 << n) - 1;
  cout << dp[all][n] << '\n';
  return 0;
}
