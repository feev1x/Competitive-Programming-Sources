/**
 *    author:  feev1x
 *    created: 10.11.2024 00:36:03
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

struct Dsu {
  vector<int> sz, p;
  int n;
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) {
        swap(u, v);
      }
      p[u] = v;
      sz[v] += sz[u];
    }
  }
  inline int size(int v) {
    return sz[get(v)];
  }
};

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; scanf("%d%d", &n, &m);
    vector<set<int>> g(n + 1);
    set<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u].emplace(v);
      g[v].emplace(u);
    }
    int cnt = m;
    for (int i = 1; i <= n; ++i) {
      st.emplace(g[i].size(), i);
    }
    vector<tuple<int, int, int>> ans;
    while ((--st.end())->first >= 2) {
      int i = (--st.end())->second;
      st.erase(--st.end());
      int u = *g[i].begin();
      g[i].erase(g[i].begin());
      st.erase({g[u].size(), u});
      g[u].erase(i);
      int v = *g[i].begin();
      g[i].erase(g[i].begin());
      st.erase({g[v].size(), v});
      g[v].erase(i);
      cnt -= 2;
      ans.emplace_back(i, u, v);
      if (g[u].count(v)) {
        g[u].erase(v);
        g[v].erase(u);
        cnt--;
      } else {
        g[u].emplace(v);
        g[v].emplace(u);
        cnt++;
      }
      st.emplace(g[i].size(), i);
      st.emplace(g[u].size(), u);
      st.emplace(g[v].size(), v);
    }
    if (cnt > 0) {
      Dsu d(n);
      for (int v = 1; v <= n; ++v) {
        for (auto u: g[v]) {
          d.unite(u, v);
        }
      }
      st.clear();
      for (int v = 1; v <= n; ++v) {
        if (d.size(v)) {
          st.emplace(d.size(v), d.get(v));
        }
      }
      debug(g, st);
      while (st.size() > 1) {
      debug(st);
        int mx = (--st.end())->second;
        int mn = st.begin()->second;
        st.erase(st.begin());
        st.erase(--st.end());
        assert(g[mx].size() >= 1);
        d.unite(mx, mn);
        st.emplace(d.size(mx), d.get(mx));
        ans.emplace_back(mx, mn, *g[mx].begin());
        g[mn].emplace(*g[mx].begin());
        g[*g[mx].begin()].emplace(mn);
        g[*g[mx].begin()].erase(mx);
        g[mx].erase(g[mx].begin());
        g[mn].emplace(mx);
        g[mx].emplace(mn);
        debug(st);
      }
    }
    debug(ans);
    assert(ans.size() < 2 * max(m, n));
    printf("%d\n", int(ans.size()));
    for (auto [A, B, C]: ans) {
      printf("%d %d %d\n", A, B, C);
    }
  }
  return 0;
}
