/**
 *    author:  feev1x
 *    created: 15.10.2024 19:49:02
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
  freopen("run.in", "r", stdin);
  freopen("run.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto chmin = [](int64_t &a, int64_t b) {
    if (a > b) {
      a = b;
      return true;
    }
    return false;
  };
  int n, k; cin >> n >> k;
  vector<int> a(k);
  vector<vector<int64_t>> b(n + 1, vector<int64_t>(n + 1));
  for (auto &u: a) cin >> u;
  for (auto &u: b) {
    for (auto &v: u) {
      cin >> v;
    }
  }
  vector<vector<int>> pcnt(n + 2);
  for (int mask = 0; mask < (1 << (n + 1)); ++mask) {
    int cnt = __builtin_popcountll(mask);
    pcnt[cnt].emplace_back(mask);
  }
  vector<vector<int64_t>> dpm((1 << (n + 1)), vector<int64_t>(n + 1, 1e18));
  vector<int64_t> dp((1 << (n + 1)), 1e18), res((1 << (n + 1)), 1e18);
  queue<pair<int, int>> q;
  q.emplace(1, 0);
  dpm[1][0] = 0;
  while (!q.empty()) {
    int mask = q.front().first;
    int cur = q.front().second;
    q.pop();
    for (int i = 1; i <= n; ++i) {
      if (mask & (1 << i)) continue;
      if (chmin(dpm[mask ^ (1 << i)][i], dpm[mask][cur] + b[cur][i])) {
        q.emplace(mask ^ (1 << i), i);
      }
    }
  }
  for (int mask = 0; mask < (1 << (n + 1)); ++mask) {
    for (int i = 0; i <= n; ++i) {
      chmin(dp[mask], dpm[mask][i] + b[i][0]);
    }
  }
  res[1] = 0;
  int sum = 0;
  for (int i = 0; i < k; ++i) {
    vector<int64_t> nres = res;
    for (auto u: pcnt[a[i] + 1]) {
      if (u % 2 == 0) continue;
      if (i == 0) {
        nres[u] = min(nres[u], dp[u]);
      } else {
        int inv = (~u) & ((1 << (n + 1)) - 1);
        inv |= 1;
        nres[u] = min(nres[u], dp[u]);
        for (int sb = inv; sb > 0; sb = (sb - 1) & inv) {
          if (sb % 2 == 0) continue;
          nres[sb | u] = min(nres[sb | u], dp[u] + res[sb]);
        }
      }
    }
    res = nres;
  }
  debug(res[(1 << (n + 1)) - 1]);
  cout << res[(1 << (n + 1)) - 1] << '\n';
}


/*
 * a[i] mask = pcnta[i]
 * ~mmask
 * smask = smask - 1 & mask
 * 11010
 * 00101
 *
 * */
