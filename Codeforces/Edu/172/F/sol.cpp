/**
 *    author:  feev1x
 *    created: 04.12.2024 08:23:15
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e16;
using mat = std::array<std::array<i64, 5>, 5>;

struct Segtree {
  std::vector<mat> t;
  std::vector<i64> a, b;
  int n;
  inline mat init(i64 a, i64 b) {
    mat c;
    c[0][0] = 0;
    c[0][1] = a + b;
    c[0][2] = a + b * 2;
    c[0][3] = -INF;
    c[0][4] = -INF;
    c[1][0] = -INF;
    c[1][1] = a;
    c[1][2] = a + b;
    c[1][3] = -INF;
    c[1][4] = -INF;
    c[2][0] = -INF;
    c[2][1] = -INF;
    c[2][2] = 0;
    c[2][3] = a + b;
    c[2][4] = a + b * 2;
    c[3][0] = -INF;
    c[3][1] = -INF;
    c[3][2] = -INF;
    c[3][3] = a;
    c[3][4] = a + b;
    c[4][4] = 0;
    return c;
  }
  inline mat comb(mat x, mat y) {
    mat res{init(-INF, -INF)};
    for (int i = 0; i < 5; ++i) {
      for (int j = i; j < 5; ++j) {
        for (int k = j; k < 5; ++k) {
          res[i][k] = std::max(res[i][k], x[i][j] + y[j][k]);
        }
      }
    }
    return res;
  }
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = init(a[tl], b[tl]);
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline void update(int v, int tl, int tr, int p) {
    if (tl == tr) {
      t[v] = init(a[tl], b[tl]);
      return;
    }
    int tm = tl + tr >> 1;
    if (p <= tm) {
      update(v << 1, tl, tm, p);
    } else {
      update(v << 1 | 1, tm + 1, tr, p);
    }
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline mat ans(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) {
      return init(-INF, -INF);
    }
    if (l <= tl && tr <= r) {
      return t[v];
    }
    int tm = tl + tr >> 1;
    return comb(ans(v << 1, tl, tm, l, r), ans(v << 1 | 1, tm + 1, tr, l, r));
  }
  Segtree(std::vector<i64> _a, std::vector<i64> _b) : n(_a.size() - 1), a(_a), b(_b) {
    t.resize(n * 4 + 5);
    build(1, 1, n);
  }
  inline void modifyA(int p, i64 x) {
    a[p] = x;
    update(1, 1, n, p);
  }
  inline void modifyB(int p, i64 x) {
    b[p] = x;
    update(1, 1, n, p);
  }
  inline i64 get(int l, int r) {
    return ans(1, 1, n, l, r)[0][4];
  }
};

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> a(n), b(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  for (auto &u: b) {
    scanf("%lld", &u);
  }
  auto One = [](std::vector<i64> &a) {
    a.emplace(a.begin(), 0);
  };
  One(a); One(b);
  Segtree t(a, b);
  int q; scanf("%d", &q);
  while (q--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int p; i64 x; scanf("%d%lld", &p, &x);
      t.modifyA(p, x);
    } else if (type == 2) {
      int p; i64 x; scanf("%d%lld", &p, &x);
      t.modifyB(p, x);
    } else {
      int l, r; scanf("%d%d", &l, &r);
      printf("%lld\n", t.get(l, r));
    }
  }
  return 0;
}
