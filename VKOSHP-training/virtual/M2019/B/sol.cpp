/**
 *    author:  feev1x
 *    created: 12.11.2024 11:41:46
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

struct Bit {
  std::vector<int> p;
  int n;
  Bit(int _n) : n(_n) {
    p.resize(n + 1);
  }
  inline int calc_(int r) {
    int sum = 0;
    for (; r > 0; r -= r & -r) {
      sum += p[r];
    }
    return sum;
  }
  inline int calc(int l, int r) {
    return calc_(r) - calc_(l - 1);
  }
  inline void modify(int r, int val) {
    for (; r <= n; r += r & -r) {
      p[r] += val;
    }
  }
};

struct Segtree {
  std::vector<int> t, psh, cnt;
  int n;
  inline void push(int v) {
    if (psh[v] != 0) {
      psh[v << 1] += psh[v];
      t[v << 1] += psh[v];
      psh[v << 1 | 1] += psh[v];
      t[v << 1 | 1] += psh[v];
      psh[v] = 0;
    }
  }
  inline std::pair<int, int> cmb(std::pair<int, int> l, std::pair<int, int> r) {
    if (l.first > r.first) {
      return r;
    } else if (l.first < r.first) {
      return l;
    }
    return {l.first, r.second + l.second};
  }
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      cnt[v] = 1;
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    std::tie(t[v], cnt[v]) = cmb({t[v << 1], cnt[v << 1]}, {t[v << 1 | 1], cnt[v << 1 | 1]});
  }
  Segtree(int _n) : n(_n) {
    t.resize((n + 1) * 4);
    cnt.resize((n + 1) * 4);
    psh.resize((n + 1) * 4);
    build(1, 1, n);
  }
  inline void update(int v, int tl, int tr, int l, int r, int val) {
    if (tl > r || l > tr) return;
    if (l <= tl && tr <= r) {
      psh[v] += val;
      t[v] += val;
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    std::tie(t[v], cnt[v]) = cmb({t[v << 1], cnt[v << 1]}, {t[v << 1 | 1], cnt[v << 1 | 1]});
  }
  inline std::pair<int, int> mn(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return {1e9, 0};
    if (l <= tl && tr <= r) return {t[v], cnt[v]};
    push(v);
    int tm = tl + tr >> 1;
    auto A = mn(v << 1, tl, tm, l, r);
    auto B = mn(v << 1 | 1, tm + 1, tr, l, r);
    return cmb(A, B);
  }
  inline void modify(int l, int r, int val) {
    update(1, 1, n, l, r, val);
  }
  inline int calc(int l, int r) {
    return mn(1, 1, n, l, r).second;
  }
};

int main() {
  int n; scanf("%d", &n);
  char S[n + 1]; scanf("%s", S);
  std::string s = S;
  s = " " + s;
  std::vector<int> vl(n + 1);
  Bit bt(n);
  Segtree t(n);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      vl[i] = 1;
      bt.modify(i, 1);
      t.modify(i, n, 1);
    } else {
      vl[i] = -1;
      bt.modify(i, -1);
      t.modify(i, n, -1);
    }
  }
  auto Solve = [&](int l, int r) {
    if (bt.calc(l, r) == 0) {
      printf("%d\n", t.calc(l, r));
    } else {
      printf("0\n");
    }
  };
  int q; scanf("%d", &q);
  while (q--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int x; scanf("%d", &x);
      if (vl[x] == 1) {
        bt.modify(x, -2);
        vl[x] = -1;
        t.modify(x, n, -2);
      } else {
        bt.modify(x, 2);
        vl[x] = 1;
        t.modify(x, n, 2);
      }
    } else {
      int l, r; scanf("%d%d", &l, &r);
      Solve(l, r);
    }
  }
  return 0;
}
