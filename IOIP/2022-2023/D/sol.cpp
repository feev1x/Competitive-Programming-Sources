/**
 *    author:  feev1x
 *    created: 06.11.2024 16:10:47
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

const int mod = 1e9 + 7;

class Dsu {
  vector<int> p, sz;
  int n;
 public:
  Dsu(int _n) : n(_n) {
    sz.assign(n + 1, 1);
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
  }
  inline void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) swap(u, v);
      p[u] = v;
      sz[v] += sz[u];
    }
  }
};

inline void mul_self(int &a, int b) {
  a = (ll)a * b % mod;
}

inline int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      mul_self(res, a);
    }
    mul_self(a, a);
    n >>= 1;
  }
  return res;
}

signed main() {
  int a, b, c; scanf("%d%d%d", &a, &b, &c);  
  Dsu d(a + b + c);
  for (int i = 1; i <= a; ++i) {
    d.unite(i, (a + b) - i + 1);
    d.unite(i, (a + c) - i + 1 + ((a + c) - i + 1 > a ? b : 0));
  }
  for (int i = 1; i <= b; ++i) {
    d.unite(i + a, (a + b) - (i + a) + 1);
    d.unite(i + a, (b + c) - i + 1 + a);
  }
  for (int i = 1; i <= c; ++i) {
    d.unite(i + a + b, (b + c) - (i + b) + 1 + a);
    d.unite(i + a + b, (a + c) - (i + a) + 1 + ((a + c) - (i + a) + 1 > a ? b : 0));
  }
  int cnt = 0;
  vector<bool> used(a + b + c);
  for (int i = 1; i <= a + b + c; ++i) {
    if (!used[d.get(i)]) {
      used[d.get(i)] = true;
      cnt++;
    }
  }
  printf("%d\n", binpow(10, cnt));
  return 0;
}
