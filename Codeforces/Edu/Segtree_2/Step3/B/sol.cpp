/**
 *    author:  feev1x
 *    created: 31.10.2024 22:38:45
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
  vector<int> t, psh;
  int n;
  inline void push(int v, int tl, int tr) {
    if (psh[v] == 0) {
      return;
    }
    psh[v << 1] ^= 1;
    psh[v << 1 | 1] ^= 1;
    int tm = tl + tr >> 1;
    t[v << 1] = (tm - tl + 1) - t[v << 1];
    t[v << 1 | 1] = (tr - tm) - t[v << 1 | 1];
    psh[v] = 0;
  }
  inline void update(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) {
      return;
    }
    if (l <= tl && tr <= r) {
      psh[v] = !psh[v];
      t[v] = (tr - tl + 1) - t[v];
      return;
    }
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r);
    update(v << 1 | 1, tm + 1, tr, l, r);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  inline int sum(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return t[v];
    }
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    return sum(v << 1, tl, tm, l, r) + sum(v << 1 | 1, tm + 1, tr, l, r);
  }
 public:
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) * 4);
    psh.resize((n + 1) * 4);
  }
  inline void modify(int l, int r) {
    update(1, 1, n, l, r);
  }
  inline int calc(int l, int r) {
    return sum(1, 1, n, l, r);
  }
};

signed main() {
  int n, m; scanf("%d%d", &n, &m);
  Segtree t(n);
  while (m--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int l, r; scanf("%d%d", &l, &r); l++;
      t.modify(l, r);
    } else {
      int k; scanf("%d", &k);
      int l = 1, r = n, ans = 0;
      while (l <= r) {
        int m = l + r >> 1, pos = t.calc(1, m);
        debug(m, pos);
        if (pos >= m) {
          r = m - 1;
          ans = m;
        } else {
          l = m + 1;
        }
      }
      printf("%d\n", ans - 1);
    }
  }
  return 0;
}
