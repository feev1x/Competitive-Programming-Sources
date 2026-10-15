#include <bits/stdc++.h>

constexpr int INF = 1e9 + 1;

inline void sort(int &a, int &b, int &c) {
  if (a > b) std::swap(a, b);
  if (c > b) std::swap(b, c);
  if (a > b) std::swap(a, b);
}

struct Segtree {
  std::vector<int> t;
  int n;
  Segtree(int n) : n(n) { t.assign(4 * n, INF); }
  inline void update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) return t[v] = std::min(t[v], x), void();
    int tm = tl + tr >> 1;
    if (i <= tm) update(v << 1, tl, tm, i, x);
    else update(v << 1 | 1, tm + 1, tr, i, x);
    t[v] = std::min(t[v << 1], t[v << 1 | 1]);
  }
  inline int get(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return INF;
    if (l <= tl && tr <= r) return t[v];
    int tm = tl + tr >> 1;
    return std::min(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline void update(int i, int x) { update(1, 1, n, i, x); }
  inline int get(int l, int r) { return get(1, 1, n, l, r); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> h(n), w(n), d(n), idx(n), idx2(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i] >> w[i] >> d[i];
    sort(h[i], w[i], d[i]);
  }
  std::sort(idx.begin(), idx.end(), [&](int i, int j) {
    return d[i] < d[j] || d[i] == d[j] && :wq

  });
  return 0;
}
