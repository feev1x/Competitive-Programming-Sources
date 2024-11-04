/**
 *    author:  feev1x
 *    created: 29.10.2024 20:34:51
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

struct Dsu {
  vector<int> sz, p;
  int n;
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int u) {
    return u == p[u] ? u : p[u] = get(p[u]);
  }
  inline void unite(int u, int v) {
    debug(u, v);
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n); n <<= 1;
    char s[n + 1]; scanf("%s", s);
    stack<pair<char, int>> stk;
    vector<vector<int>> g(n + 1);
    Dsu d(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stk.emplace('(', i + 1);
      } else {
        if (!stk.empty()) {
          d.unite(stk.top().second, i + 1);
          stk.pop();
          if (!stk.empty()) {
            d.unite(stk.top().second + 1, i + 1);
          } else {
            d.unite(1, i + 1);
          }
        }
      }
    }
    set<int> st;
    for (int i = 1; i <= n; ++i) {
      st.emplace(d.get(i));
    }
    cout << st.size() << '\n';
  }
  return 0;
}
