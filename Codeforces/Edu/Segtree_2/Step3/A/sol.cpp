/**
 *    author:  feev1x
 *    created: 31.10.2024 22:06:31
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

class Segtree {
  vector<ll> p, s, mx, psh, sum;
  int n;
  inline ll cmb(int u, int v) {
    return max({mx[u], mx[v], p[u], s[v], s[u] + p[v]});
  }
  inline void push(int v, int tl, int tr) {
    if (psh[v] == 1e18) return;
    ll val = psh[v];
    psh[v << 1] = psh[v];
    psh[v << 1 | 1] = psh[v];
    int tm = tl + tr >> 1;
    if (val <= 0) {
      p[v << 1] = s[v << 1] = mx[v << 1] = p[v << 1 | 1] = s[v << 1 | 1] = mx[v << 1 | 1] = 0;
    } else {
      p[v << 1] = s[v << 1] = mx[v << 1] = val * (tm - tl + 1);
      p[v << 1 | 1] = s[v << 1 | 1] = mx[v << 1 | 1] = val * (tr - (tm + 1) + 1);
    }
    sum[v << 1] = val * (tm - tl + 1);
    sum[v << 1 | 1] = val * (tr - (tm + 1) + 1);
    psh[v] = 1e18;
  }
  inline void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > tr || tl > r) return;
    if (l <= tl && tr <= r) {
      if (val <= 0) {
        p[v] = s[v] = mx[v] = 0;
      } else {
        p[v] = s[v] = mx[v] = val * (tr - tl + 1);
      }
      sum[v] = val * (tr - tl + 1);
      psh[v] = val;
      return;
    }
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    mx[v] = cmb(v << 1, v << 1 | 1);
    p[v] = max(p[v << 1], sum[v << 1] + p[v << 1 | 1]);
    s[v] = max(s[v << 1 | 1], s[v << 1] + sum[v << 1 | 1]);
    sum[v] = sum[v << 1] + sum[v << 1 | 1];
  }
 public:
  Segtree(int _n) : n(_n) {
    p.resize((n + 1) * 4);
    sum.resize((n + 1) * 4);
    psh.assign((n + 1) * 4, 1e18);
    s.resize((n + 1) * 4);
    mx.resize((n + 1) * 4);
  }
  inline void modify(int l, int r, ll val) {
    update(1, 1, n, l, r, val);
  }
  inline ll calc() {
    return mx[1];
  }
};

signed main() {
  int n, m; scanf("%d%d", &n, &m);
  Segtree t(n);
  while (m--) {
    int l, r; ll v; scanf("%d%d%lld", &l, &r, &v); l++;
    t.modify(l, r, v);
    printf("%lld\n", t.calc());
  }
  return 0;
}
