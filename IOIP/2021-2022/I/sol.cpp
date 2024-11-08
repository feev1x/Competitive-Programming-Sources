/**
 *    author:  feev1x
 *    created: 07.11.2024 20:46:24
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

const ll inf = numeric_limits<ll>::max();

struct Point {
  int x, y, i;
  ll dis(Point &sm) {
    ll dlx = x - sm.x;
    ll dly = y - sm.y;
    return dlx * dlx + dly * dly;
  }
};

struct Edge {
  ll w = inf;
  int to = -1;
};

signed main() {
  int n, m; scanf("%d%d", &n, &m);
  vector<Point> org(n);
  for (auto &[x, y, i]: org) {
    scanf("%d%d", &x, &y);
  }
  vector<Point> sim(m);
  for (auto &[x, y, i]: sim) {
    scanf("%d%d", &x, &y);
  }
  for (int i = 0; i < n; ++i) {
    org[i].i = i + 1;
  }
  for (int i = 0; i < m; ++i) {
    sim[i].i = i + 1;
  }
  auto Organs = [&](int &v) {
    ll res = 0;
    for (auto &u: org) {
      res += sim[v].dis(u);
    }
    return res;
  };
  vector<vector<int>> g(m);
  auto Solve = [&](int &v) {
    ll res = Organs(v);
    vector<bool> used(m);
    int cnt = 0;
    vector<Edge> min_e(m);
    min_e[0].w = 0;
    for (int i = 0; i < m; ++i) {
      int v = -1;
      for (int j = 0; j < m; ++j) {
        if (!used[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
          v = j;
        }
      }
      used[v] = true;
      res += min_e[v].w;
      if (min_e[v].to != -1) {
        g[v].emplace_back(min_e[v].to);
        g[min_e[v].to].emplace_back(v);
        cnt++;
      }
      for (int to = 0; to < m; ++to) {
        if (sim[v].dis(sim[to]) < min_e[to].w) {
          min_e[to].w = sim[v].dis(sim[to]);
          min_e[to].to = v;
        }
      }
    }
    return pair{res, cnt};
  };
  ll len = inf;
  int opt = -1;
  for (int i = 0; i < m; ++i) {
    ll _len = Organs(i);
    if (_len < len) {
      opt = i;
      len = _len;
    }
  }
  auto [res, cnt] = Solve(opt);
  printf("%lld\n%d\n", res, n + cnt);
  for (auto &u: org) {
    printf("s %d -> %d\n", u.i, opt + 1);
  }
  vector<pair<int, int>> e;
  function<void(int&, int&)> Dfs = [&](int &v, int &p) {
    for (auto &to: g[v]) {
      if (to == p) continue;
      e.emplace_back(v + 1, to + 1);
      Dfs(to, v);
    }
  };
  Dfs(opt, opt);
  for (auto &[u, v]: e) {
    printf("u %d -> %d\n", u, v);
  }
  return 0;
}
