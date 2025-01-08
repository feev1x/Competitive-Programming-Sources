/**
 *    author:  feev1x
 *    created: 03.01.2025 12:02:02
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Segtree {
  std::vector<int> t, psh;
  int n;
  inline void push(int v) {
    
  }
  inline void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > tr || tl > r) {
      return;
    }
    if (l <= tl && tr <= r) {
      if (x == -1) {
        psh[v] = 0;
        t[v] += x * (tr - tl + 1);
      }
    }
  }
  Segtree() : n(0) {}
  Segtree(int _n) : n(_n) {
    t.resize(n * 4 + 5);
    psh.resize(n * 4 + 5);
  }
  inline void modify(int l, int r, int x) {
    update(1, 1, n, l, r, x);
  }
  inline int get(int l, int r) {
    return ans(1, 1, n, l, r);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> h(n);
  std::vector<Segtree> t(n + 1, Segtree(n));
  for (auto &u: h) {
    std::cin >> u;
  }
  h.emplace(h.begin(), 0);
  for (int i = 1; i <= n; ++i) {
    long double mx = -1;
    for (int j = i + 1; j <= n; ++j) {
      long double slope = h[j] / (long double)j;
      if (slope > mx) {
        t[j].modify(i, i, 1);
        mx = slope;
      }
    }
    for (int j = 1; j <= n; ++j) {
      t[j].modify(i, i, t[j].get(i - 1, i - 1));
    }
  }
  int q; std::cin >> q;
  while (q--) {
    int x, y; std::cin >> x >> y;
    long double sl = (h[x] + y) / (long double)x;
    for (int i = x + 1; i <= n; ++i) {
      long double slope = h[i] / (long double)i;
      if (sl > slope) {
        t[i].modify(1, x - 1, -1);
      }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res += pref[i].get(n, n);
    }
    std::cout << res << '\n';
  }
  return 0;
}
