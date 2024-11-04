/**
 *    author:  feev1x
 *    created: 02.11.2024 18:42:35
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
  vector<int> t;
  int n;
  inline void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
      t[v]++;
      return;
    }
    int tm = tl + tr >> 1;
    if (pos <= tm) {
      update(v << 1, tl, tm, pos);
    } else {
      update(v << 1 | 1, tm + 1, tr, pos);
    }
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  inline int sum(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return sum(v << 1, tl, tm, l, r) + sum(v << 1 | 1, tm + 1, tr, l, r);
  }
 public:
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) << 2);
  }
  inline void modify(int pos) {
    update(1, 1, n, pos);
  }
  inline int calc(int l, int r) {
    if (l > r) return 0;
    return sum(1, 1, n, l, r);
  }
};

signed main() {
  int n, m; scanf("%d%d", &n, &m);
  vector<ll> p(n + 1), s(n + 1);
  vector<int> cnt(n + 1), a(n + 1);
  Segtree t(m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    p[i] = (p[i - 1] + a[i]) % m;
    s[i] = s[i - 1] + p[i - 1];
    cnt[i] = t.calc(p[i] + 2, m);
    t.modify(p[i] + 1);
  }
  ll res = 0;
  for (int r = 1; r <= n; ++r) {
    res += p[r] * r - s[r] + (ll)cnt[r] * m;
  }
  printf("%lld\n", res);
  return 0;
}
