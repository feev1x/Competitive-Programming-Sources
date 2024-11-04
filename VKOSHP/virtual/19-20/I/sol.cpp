/**
 *    author:  feev1x
 *    created: 25.10.2024 10:04:59
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  if (n == 3) {
    cout << "1 2 3\n";
    return 0;
  }
  vector<array<int, 3>> a(n + 1);
  vector<vector<int>> nm(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        nm[a[i][j]].emplace_back(a[i][k]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    sort(nm[i].begin(), nm[i].end());
    nm[i].erase(unique(nm[i].begin(), nm[i].end()), nm[i].end());
  }
  vector<int> ans(n + 1);
  vector<bool> used(n + 1);
  int nw = 1;
  ans[1] = nw;
  used[1] = true;
  auto Cnt = [&](int i, int j) {
    int cnt = 0;
    for (auto u: nm[i]) {
      if (u == i || u == j) continue;
      for (auto v: nm[j]) {
        if (v == i || v == j) continue;
        if (u == v) cnt++;
      }
    }
    return cnt;
  };
  auto Check = [&](int i, int j) {
    for (auto u: nm[i]) {
      if (u == j) return true;
    }
    return false;
  };
  auto Sim = [&](int i, int j) {
    for (auto u: nm[i]) {
      if (u == i || u == j) continue;
      for (auto v: nm[j]) {
        if (v == i || v == j) continue;
        if (u == v) return u;
      }
    }
    return -1;
  };
  auto Find = [&](int i, int j) {
    for (auto u: nm[i]) {
      if (u == j) return true;
    }
    return false;
  };
  for (int i = 1; i < n; i += 2) {
    int use = -1;
    for (auto u: nm[nw]) {
      if (used[u]) continue;
      debug(nm[u], u);
      if (Cnt(nw, u) == 2) {
        debug(u);
        ans[i + 1] = u;
        use = u;
        break;
      }
    }
    debug(use, nm[nw], i, nw);
    used[use] = true;
    if (i + 2 <= n) {
      for (auto u: nm[nw]) {
        if (used[u]) continue;
        debug(nm[u], u);
        debug(Cnt(nw, u));
        debug(used);
        if (Cnt(nw, u) == 1 && Sim(nw, u) == use) {
          ans[i + 2] = u;
          debug(u);
          use = u;
          used[u] = true;
          break;
        }
      }
    }
    if (Cnt(nw, use) == 2 && i + 2 <= n) {
      for (auto u: nm[nw]) {
        if (used[u]) continue;
        debug(nm[u], u);
        debug(Cnt(nw, u));
        debug(used);
        if (Cnt(nw, u) == 2 && Find(u, use) == true) {
          ans[i + 2] = u;
          debug(u);
          use = u;
          used[u] = true;
          break;
        }
      }
    }
    used[use] = true;
    nw = use;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
