/**
 *    author:  feev1x
 *    created: 30.11.2024 18:42:43
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Segtree {
  std::vector<int> t, psh;
  int n;
  inline void push(int v) {
    if (psh[v]) {
      t[v << 1] = t[v << 1 | 1] = psh[v << 1] = psh[v << 1 | 1] = psh[v];
      psh[v] = 0;
    }
  }
  inline int min(int a, int b) {
    if (a == 0) {
      return b;
    }
    if (b == 0) {
      return a;
    }
    if (a > b) {
      return b;
    }
    return a;
  }
  inline void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > tr || tl > r) {
      return;
    }
    if (l <= tl && tr <= r) {
      t[v] = psh[v] = x;
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, x);
    update(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
  }
  inline int mn(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return t[v];
    }
    push(v);
    int tm = tl + tr >> 1;
    int a = mn(v << 1, tl, tm, l, r);
    int b = mn(v << 1 | 1, tm + 1, tr, l, r);
    return min(a, b);
  }
  Segtree(int _n) : n(_n) {
    t.resize(n * 4 + 5);
    psh.resize(n * 4 + 5);
  }
  inline void modify(int l, int r, int x) {
    update(1, 1, n, l, r, x);
  }
  inline int calc(int l, int r) {
    return mn(1, 1, n, l, r);
  }
};

int main() {
  int h, w, n; scanf("%d%d%d", &h, &w, &n);
  std::vector<std::tuple<int, int, int, int>> a;
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int r, c, l; scanf("%d%d%d", &r, &c, &l);
    a.emplace_back(r, c, l, i);
  }
  std::sort(a.begin(), a.end(), std::greater<>());
  Segtree t(w);
  for (auto [r, c, l, i]: a) {
    int mn = t.calc(c, c + l - 1);
    int lev;
    if (mn == 0) {
      lev = h;
    } else {
      lev = mn - 1;
    }
    t.modify(c, c + l - 1, lev);
    ans[i] = lev;
  }
  for (auto u: ans) {
    printf("%d\n", u);
  }
  return 0;
}
