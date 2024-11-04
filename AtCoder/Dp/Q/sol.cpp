/**
 *    author:  feev1x
 *    created: 18.10.2024 08:30:46
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
  vector<int64_t> t;
  int n;
  inline void update(int v, int tl, int tr, int pos, int64_t val) {
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
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
  inline int64_t mx(int v, int tl, int tr ,int l, int r) {
    if (l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return max(mx(v << 1, tl, tm, l, r), mx(v << 1 | 1, tm + 1, tr, l, r));
  }
 public:
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) * 4);
  }
  inline void modify(int pos, int64_t val) {
    update(1, 1, n, pos, val);
  }
  inline int64_t calc(int l, int r) {
    return mx(1, 1, n, l, r);
  }
};

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> h(n + 1);
  vector<int64_t> a(n + 1), dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  Segtree t(n);
  int64_t res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = t.calc(1, h[i]) + a[i];
    t.modify(h[i], dp[i]);
    res = max(res, dp[i]);
  }
  cout << res << '\n';
  return 0;
}
