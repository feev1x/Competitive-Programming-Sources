/**
 *    author:  feev1x
 *    created: 23.10.2024 09:16:54
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
  vector<int64_t> t, a;
  int n;
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
  }
  inline int64_t mn(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return 1e18;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return min(mn(v << 1, tl, tm, l, r), mn(v << 1 | 1, tm + 1, tr, l, r));
  }
 public:
  Segtree(vector<int64_t> _a) : a(_a), n(_a.size()) {
    t.resize(n * 4);
    n--;
    build(1, 1, n);
  }
  inline int64_t calc(int l, int r) {
    return mn(1, 1, n, l, r);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n; cin >> n;
  vector<int64_t> a(n + 1), p(n + 1);
  int64_t sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
    p[i] = a[i] + p[i - 1];
  }
  Segtree t(a);
  sum = (sum + 1) / 2;
  int64_t res = n;
  for (int64_t i = 1; i <= n; ++i) {
    int64_t l = i, r = n, ans = 0;
    while (l <= r) {
      int64_t m = l + r >> 1;
      if (p[m] - p[i - 1] - t.calc(i + 1, m) >= sum) {
        r = m - 1;
        ans = m;
      } else {
        l = m + 1;
      }
    }
    if (ans == 0) continue;
    res = min(res, ans - i);
  }
  cout << res << '\n';
  return 0;
}

