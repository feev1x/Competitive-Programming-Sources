/**
 *    author:  feev1x
 *    created: 11.11.2024 19:49:29
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
  std::vector<i64> p;
  int n;
  Bit(int _n) : n(_n) {
    p.resize(n + 1);
  }
  Bit(std::vector<i64> a) : Bit(int(a.size()) - 1) {
    for (int i = 1; i <= n; ++i) {
      p[i] += a[i];
      int r = i + (i & -i);
      if (r <= n) {
        p[r] += p[i];
      }
    }
  }
  inline i64 calc_(int r) {
    i64 sum = 0;
    for (; r > 0; r -= r & -r) {
      sum += p[r];
    }
    return sum;
  }
  inline i64 calc(int l, int r) {
    return calc_(r) - calc_(l - 1);
  }
  inline void modify(int r, int val) {
    val = val - calc(r, r);
    for (; r <= n; r += r & -r) {
      p[r] += val;
    }
  }
};

int main() {
  int n, q; scanf("%d%d", &n, &q);
  std::vector<i64> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  Bit bt(a);
  while (q--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      int k; i64 u; scanf("%d%lld", &k, &u);
      bt.modify(k, u);
    } else {
      int l, r; scanf("%d%d", &l, &r);
      printf("%lld\n", bt.calc(l, r));
    }
  }
  return 0;
}
