#include <bits/stdc++.h>

struct Node {
  int64_t mx = 0, sum = 0;
};

struct Segtree {
  std::vector<Node> t;
  int n;
  Segtree(int n) : n(n) { t.resize(4 * n); }
  inline Node comb(Node a, Node b) {
    Node res;
    res.mx = std::max(a.mx, b.mx);
    res.sum = a.sum + b.sum;
    return res;
  }
  inline void update(int v, int tl, int tr, int i, int64_t x) {
    if (tl == tr) return t[v] = {x, x}, void();
    int tm = tl + tr >> 1;
    if (i <= tm) update(v << 1, tl, tm, i, x);
    else update(v << 1 | 1, tm + 1, tr, i, x);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline Node get(int v, int tl, int tr, int l, int r) {
    if (l > tr || tl > r) return {0, 0};
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline void update(int i, int64_t x) { update(1, 1, n, i, x); }
  inline Node get(int l, int r) { return get(1, 1, n, l, r); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<int> a(n + 1);
  Segtree t(n);
  for (int i = 1; i <= n; ++i) std::cin >> a[i], t.update(i, a[i]);
  while (q--) {
    int l, r; std::cin >> l >> r;
    Node g = t.get(l, r);
    int64_t sum = g.sum - g.mx;
    if (g.mx > sum) {
      std::cout << g.mx << '\n';
    } else {
      std::cout << (g.sum + 1) / 2 << '\n';
    }
  }
  return 0;
}
