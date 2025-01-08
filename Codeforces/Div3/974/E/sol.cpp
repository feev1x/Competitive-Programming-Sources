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
  int tt; cin >> tt;
  while (tt--) {
    int n, m, h; cin >> n >> m >> h;
    vector<int> a(h);
    map<int, bool> hr;
    for (auto &u: a) cin >> u, hr[u] = true;
    vector<vector<pair<int, int64_t>>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
      int u, v, w; cin >> u >> v >> w;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    auto dijkstra = [&](int str) {
      vector<int64_t> d(n + 1, 1e18), dhr(n + 1, 1e18);
      d[str] = 0;
      set<pair<int, int>> q, st;
      q.emplace(d[str], str);
      while (!q.empty()) {
        int near = q.begin()->second;
        if (hr[near]) {
          dhr[near] = d[near];
          st.emplace(dhr[near], near);
        }
        q.erase(q.begin());
        for (auto [to, w]: g[near]) {
          if (d[to] > w + d[near]) {
            q.erase({d[to], to});
            d[to] = w + d[near];
            q.emplace(d[to], to);
          }
        }
      }
      while (!st.empty()) {
        int near = st.begin()->second;
        st.erase(st.begin());
        for (auto [to, w]: g[near]) {
          if (dhr[to] > w / 2 + dhr[near]) { 
            st.erase({dhr[to], to});
            dhr[to] = w / 2 + dhr[near];
            st.emplace(dhr[to], to);
          }
        }
      }
      for (int i = 1; i <= n; ++i) {
        d[i] = min(d[i], dhr[i]);
      }
      return d;
    };
    auto one = dijkstra(1);
    auto nth = dijkstra(n);
    if (one[n] == 1e18) {
      cout << -1 << '\n';
      continue;
    }
    int64_t res = 1e18;
    for (int i = 1; i <= n; ++i) {
      res = min(res, max(one[i], nth[i]));
    }
    cout << res << '\n';
  }
}

