/**
 *    author:  feev1x
 *    created: 04.11.2024 23:09:55
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
  vector<ll> t;
  int n;
  inline void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    int tm = tl + tr >> 1;
    if (pos <= tm) {
      update(v << 1, tl, tm, pos, val);
    } else {
      update(v << 1 | 1, tm + 1, tr, pos, val);
    }
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  inline ll sum(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return 0ll;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return sum(v << 1, tl, tm, l, r) + sum(v << 1 | 1, tm + 1, tr, l, r);
  }
 public:
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) * 4);
  }
  inline void modify(int pos, ll val) {
    update(1, 1, n, pos, val);
  }
  inline ll calc(int l, int r) {
    return sum(1, 1, n, l, r);
  }
};

signed main() {
  int n, q; scanf("%d%d", &n, &q);
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  Segtree t(n);
  for (int i = 1; i <= n; ++i) {
    t.modify(i, a[i]);
  }
  while (q--) {
    int k; scanf("%d", &k);
    if (k == 1) {
      ll u; scanf("%d%lld", &k, &u);
      t.modify(k, u);
    } else {
      int l, r; scanf("%d%d", &l, &r);
      printf("%lld\n", t.calc(l, r));
    }
  }
  return 0;
}
