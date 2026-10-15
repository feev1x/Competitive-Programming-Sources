#include <bits/stdc++.h>

constexpr int INF = 1e9 + 5;

struct Node {
  int res = -INF, h = 0, c = -INF, ph = 0;
};

struct Segtree {
  std::vector<Node> t;
  int n;
  Segtree(int n) : n(n) { t.resize(4 * n); }
  inline void push(int v) {
    if (t[v].ph) {
      t[v << 1].h = std::max(t[v << 1].h, t[v].ph);
      t[v << 1 | 1].h = std::max(t[v << 1 | 1].h, t[v].ph);
      t[v << 1].ph = std::max(t[v << 1].ph, t[v].ph);
      t[v << 1 | 1].ph = std::max(t[v << 1 | 1].ph, t[v].ph);
      t[v << 1].res = std::max(t[v << 1].res, t[v].ph + t[v << 1].c);
      t[v << 1 | 1].res = std::max(t[v << 1 | 1].res, t[v].ph + t[v << 1 | 1].c);
      t[v].ph = 0;
    }
  }
  inline Node comb(int vl, Node a, Node b) {
    Node res;
    res.h = std::max(a.h, b.h);
    res.c = std::max(a.c, b.c);
    res.res = std::max({vl, a.res, b.res});
    return res;
  }
  inline void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > tr || tl > r) return;
    if (l <= tl && tr <= r) {
      t[v].h = std::max(t[v].h, x);
      t[v].ph = std::max(t[v].ph, x);
      t[v].res = std::max(t[v].res, x + t[v].c);
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, x);
    update(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v] = comb(t[v].res, t[v << 1], t[v << 1 | 1]);
  }
  inline void update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
      t[v].c = x;
      t[v].h = t[v].ph = 0;
      t[v].res = std::max(t[v].res, t[v].h + t[v].c);
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    if (i <= tm) update(v << 1, tl, tm, i, x);
    else update(v << 1 | 1, tm + 1, tr, i, x);
    t[v] = comb(t[v].res, t[v << 1], t[v << 1 | 1]);
  }
  inline int get(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return -INF;
    if (l <= tl && tr <= r) return t[v].res;
    push(v);
    int tm = tl + tr >> 1;
    return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline void update(int l, int r, int x) { update(1, 1, n, l, r, x); }
  inline void update(int i, int x) { update(1, 1, n, i, x); }
  inline int get(int l, int r) {
    int val = get(1, 1, n, l, r);
    return (val < 0 ? -1 : val);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> h(n + 1), a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> h[i] >> a[i] >> b[i];
  int q; std::cin >> q;
  std::vector<int> ans(q, -1), l(q), r(q);
  std::vector<std::vector<int>> qq(n + 1);
  std::vector<std::vector<int>> add(n + 1), del(n + 1);
  for (int i = 0; i < q; ++i) std::cin >> l[i] >> r[i];
  {
    for (int i = 0; i < q; ++i) qq[r[i]].emplace_back(i);
    for (int i = 1; i <= n; ++i) {
      if (i + a[i] <= n) add[i + a[i]].emplace_back(i);
      if (i + b[i] + 1 <= n) del[i + b[i] + 1].emplace_back(i);
    }
    Segtree t(n);
    for (int i = 1; i <= n; ++i) {
      for (auto idx: add[i]) t.update(idx, -h[idx]);
      for (auto idx: del[i]) t.update(idx, -INF);
      std::vector<int>().swap(add[i]);
      std::vector<int>().swap(del[i]);
      int L = std::max(1, i - b[i]), R = i - a[i];
      if (L <= R) t.update(L, R, h[i]);
      for (auto j: qq[i]) ans[j] = std::max(ans[j], t.get(l[j], i));
      std::vector<int>().swap(qq[i]);
    }
  }
  std::reverse(h.begin() + 1, h.end());
  std::reverse(a.begin() + 1, a.end());
  std::reverse(b.begin() + 1, b.end());
  for (int i = 0; i < q; ++i) l[i] = n - l[i] + 1, r[i] = n - r[i] + 1, std::swap(l[i], r[i]);
  {
    for (int i = 0; i < q; ++i) qq[r[i]].emplace_back(i);
    for (int i = 1; i <= n; ++i) {
      if (i + a[i] <= n) add[i + a[i]].emplace_back(i);
      if (i + b[i] + 1 <= n) del[i + b[i] + 1].emplace_back(i);
    }
    Segtree t(n);
    for (int i = 1; i <= n; ++i) {
      for (auto idx: add[i]) t.update(idx, -h[idx]);
      for (auto idx: del[i]) t.update(idx, -INF);
      std::vector<int>().swap(add[i]);
      std::vector<int>().swap(del[i]);
      int L = std::max(1, i - b[i]), R = i - a[i];
      if (L <= R) t.update(L, R, h[i]);
      for (auto j: qq[i]) ans[j] = std::max(ans[j], t.get(l[j], i));
    }
  }
  for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
  return 0;
}
