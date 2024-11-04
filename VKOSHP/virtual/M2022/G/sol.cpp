/**
 *    author:  feev1x
 *    created: 19.10.2024 17:14:53
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
  vector<int> t;
  int n;
  inline void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
      t[v] = 1;
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
    int A = sum(v << 1, tl, tm, l, r), B = 
      sum(v << 1 | 1, tm + 1, tr, l, r);
    return A + B;
  }
 public:
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) * 4);
  }
  inline void modify(int pos) {
    update(1, 1, n, pos);
  }
  inline int calc(int l, int r) {
    return sum(1, 1, n, l, r);
  }
};

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> p(n + 1), d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  Segtree t(n), inv(n);
  for (int i = 1; i <= n; ++i) {
    d[i] = d[i] + t.calc(1, p[i]) - t.calc(p[i], n);
    t.modify(p[i]);
  }
  sort(d.begin() + 1, d.end());
  int64_t res = 0;
  for (int i = 1; i <= n; ++i) {
    res += inv.calc(p[i], n);
    inv.modify(p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    res += d[i];
    cout << res << " \n"[i == n];
  }
  return 0;
}
