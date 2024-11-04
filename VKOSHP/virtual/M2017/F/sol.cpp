/**
 *    author:  feev1x
 *    created: 21.10.2024 15:56:04
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

class Segtree {
  vector<int64_t> tor, tmx, ar;
  int n;
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      tor[v] = tmx[v] = ar[tl];
      return;
    } int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    tor[v] = tor[v << 1] | tor[v << 1 | 1];
    tmx[v] = max(tmx[v << 1], tmx[v << 1 | 1]);
  }
  inline int64_t mx(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return -1;
    if (l <= tl && tr <= r) return tmx[v];
    int tm = tl + tr >> 1;
    return max(mx(v << 1, tl, tm, l, r), mx(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline int64_t get(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return tor[v];
    int tm = tl + tr >> 1;
    return get(v << 1, tl, tm, l, r) | get(v << 1 | 1, tm + 1, tr, l, r);
  }
 public:
  Segtree(vector<int64_t> _ar) : ar(_ar), n(_ar.size()) {
    tor.resize(n * 4);
    tmx.resize(n * 4);
    n--;
    build(1, 1, n);
  }
  inline int64_t Max(int l, int r) {
    return mx(1, 1, n, l, r);
  }
  inline int64_t Or(int l, int r) {
    return get(1, 1, n, l, r);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  a.emplace(a.begin(), 0);
  Segtree t(a);
  auto Count = [&](int64_t v) {
    int64_t lmx, rmx;
    int64_t l = 1, r = v - 1, ans = v;
    while (l <= r) {
      int64_t m = l + r >> 1;
      if (t.Max(m, v - 1) > a[v]) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    lmx = ans;
    l = v + 1, r = n, ans = v;
    while (l <= r) {
      int64_t m = l + r >> 1;
      if (t.Max(v + 1, m) >= a[v]) {
        r = m - 1;
      } else {
        l = m + 1;
        ans = m;
      }
    }
    rmx = ans;
    debug(lmx, rmx, v, a[v]);
    int64_t cl = 0, cr = 0;
    l = v + 1, r = rmx, ans = rmx + 1;
    while (l <= r) {
      int64_t m = l + r >> 1;
      debug(t.Or(v, m));
      if (t.Or(v, m) > a[v]) {
        r = m - 1;
        ans = m;
      } else {
        l = m + 1;
      }
    }
    cr = ans;
    l = lmx, r = v - 1, ans = lmx - 1;
    while (l <= r) {
      int64_t m = l + r >> 1;
      debug(t.Or(m, v));
      if (t.Or(m, v) > a[v]) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }
    cl = ans;
    debug(cl, cr);
    int64_t al = v - cl;
    int64_t ar = rmx - v + 1;
    int64_t res = (cl - lmx + 1) * ar + (rmx - cr + 1) * al;
    debug(res);
    return res;
  };
  int64_t res = 0;
  for (int i = 1; i <= n; ++i) {
    res += Count(i);
  }
  cout << res << '\n';
  return 0;
}
