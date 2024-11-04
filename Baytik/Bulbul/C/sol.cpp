/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  int s, t, l; cin >> s >> t >> l;
  int64_t k; cin >> k;
  vector<vector<pair<int, int>>> g(n + 1);
  while (m--) {
    int a, b, c; cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  vector<int64_t> ds(n + 1, 1e18), dt(n + 1, 1e18);
  set<pair<int64_t, int>> q;
  ds[s] = 0;
  dt[t] = 0;
  q.emplace(ds[s], s);
  while (!q.empty()) {
    int cur = q.begin()->second;
    q.erase(q.begin());
    for (auto [to, w]: g[cur]) {
      if (ds[to] > ds[cur] + w) {
        q.erase({ds[to], to});
        ds[to] = ds[cur] + w;
        q.emplace(ds[to], to);
      }
    }
  }
  q.emplace(dt[t], t);
  while (!q.empty()) {
    int cur = q.begin()->second;
    q.erase(q.begin());
    for (auto [to, w]: g[cur]) {
      if (dt[to] > dt[cur] + w) {
        q.erase({dt[to], to});
        dt[to] = dt[cur] + w;
        q.emplace(dt[to], to);
      }
    }
  }
  if (ds[t] <= k) {
    cout << n * (n - 1) / 2 << '\n';
    return 0;
  }
  dt.erase(dt.begin());
  sort(dt.begin(), dt.end());
  int64_t res = 0;
  for (int u = 1; u <= n; ++u) {
    res += int64_t(upper_bound(dt.begin(), dt.end(), k - ds[u] - l) - dt.begin());
  }
  cout << res << '\n';
}


