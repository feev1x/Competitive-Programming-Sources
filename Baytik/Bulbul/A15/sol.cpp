/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l; cin >> n >> l;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  vector<vector<vector<int>>> dp((1 << n), vector<vector<int>>(n, vector<int>(l + 1)));
  vector<vector<vector<bool>>> in((1 << n), vector<vector<bool>>(n, vector<bool>(l + 1)));
  queue<tuple<int, int, int>> q;
  q.emplace(0, -1, 0);
  for (int i = 0; i < n; ++i) dp[0][i][0] = 1;
  while (!q.empty()) {
    auto [mask, j, sum] = q.front();
    q.pop();
    bool ok = j == -1;
    for (int i = 0; i < n; ++i) {
      if (mask & i) continue;
      if (ok) j = i;
      if (sum + abs(a[j] - a[i]) <= l) {
        dp[mask | (1 << i)][i][sum + abs(a[j] - a[i])] += dp[mask][j][sum];
        if (!in[mask | (1 << i)][i][sum + abs(a[j] - a[i])]) 
          q.emplace(mask | (1 << i), i, sum + abs(a[j] - a[i])),
          in[mask | (1 << i)][i][sum + abs(a[j] - a[i])] = true;
      }
    }
  }
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= l; ++j) {
      res += dp[(1 << n) - 1][i][j];
    }
  }
  cout << res << '\n';
}

