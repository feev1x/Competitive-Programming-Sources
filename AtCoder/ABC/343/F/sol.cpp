#include <bits/stdc++.h>

struct Node {
  int mx = 0, mx2 = 0, cmx = 0, cmx2 = 0;
};

struct Segtree {
  std::vector<Node> t;
  int n;
  Segtree(int n) : n(n) { t.resize(4 * n); }
  inline Node comb(Node a, Node b) {
    Node res;
    res.mx = std::max(a.mx, b.mx);
    if (a.mx < res.mx) res.mx2 = std::max(res.mx2, a.mx);
    if (b.mx < res.mx) res.mx2 = std::max(res.mx2, b.mx);
    if (a.mx2 < res.mx) res.mx2 = std::max(res.mx2, a.mx2);
    if (b.mx2 < res.mx) res.mx2 = std::max(res.mx2, b.mx2);
    if (a.mx == res.mx) res.cmx += a.cmx;
    if (b.mx == res.mx) res.cmx += b.cmx;
    if (a.mx == res.mx2) res.cmx2 += a.cmx;
    if (b.mx == res.mx2) res.cmx2 += b.cmx;
    if (a.mx2 == res.mx2) res.cmx2 += a.cmx2;
    if (b.mx2 == res.mx2) res.cmx2 += b.cmx2;
    return res;
  }
  inline void update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) return t[v] = {x, 0, 1, 0}, void();
    int tm = tl + tr >> 1;
    if (i <= tm) update(v << 1, tl, tm, i, x);
    else update(v << 1 | 1, tm + 1, tr, i, x);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline Node get(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return {0, 0, 0, 0};
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline void update(int i, int x) { update(1, 1, n, i, x); }
  inline int get(int l, int r) { return get(1, 1, n, l, r).cmx2; }
};

int main() { 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<int> a(n + 1);
  Segtree t(n);
  for (int i = 1; i <= n; ++i) std::cin >> a[i], t.update(i, a[i]);
  while (q--) {
    int type, x, y; std::cin >> type >> x >> y;
    if (type == 1) t.update(x, y);
    else std::cout << t.get(x, y) << '\n';
  }
  return 0;
}
