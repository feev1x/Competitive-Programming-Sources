#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline bool chmin(int &a, int b) { return a > b ? a = b, true : false; }

struct Node {
  int min = INF, psh = INF, idx = -1, pshidx = -1;
};

struct Segtree {
  std::vector<Node> t;
  int n;
  Segtree(int n) : n(n) { t.resize(4 * n); }
  inline Node comb(Node a, Node b) {
    Node res;
    res.min = std::min(a.min, b.min);
    res.idx = res.min == a.min ? a.idx : b.idx;
    return res;
  }
  inline void push(int v) {
    if (t[v].pshidx != -1) {
      if (chmin(t[v << 1].psh, t[v].psh)) t[v << 1].pshidx = t[v].pshidx;
      if (chmin(t[v << 1].min, t[v].psh)) t[v << 1].idx = t[v].pshidx;
      if (chmin(t[v << 1 | 1].psh, t[v].psh)) t[v << 1 | 1].pshidx = t[v].pshidx;
      if (chmin(t[v << 1 | 1].min, t[v].psh)) t[v << 1 | 1].idx = t[v].pshidx;
      t[v].psh = INF, t[v].pshidx = -1;
    }
  }
  inline void update(int v, int tl, int tr, int l, int r, int x, int id) {
    if (tl > r || l > tr) return;
    if (l <= tl && tr <= r) {
      if (chmin(t[v].min, x)) t[v].idx = id;
      if (chmin(t[v].psh, x)) t[v].pshidx = id;
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, x, id);
    update(v << 1 | 1, tm + 1, tr, l, r, x, id);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline Node get(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return Node();
    if (l <= tl && tr <= r) return t[v];
    push(v);
    int tm = tl + tr >> 1;
    return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }
  inline void update(int l, int r, int x, int id) { update(1, 0, n - 1, l, r, x, id); }
  inline Node get(int l, int r) { return get(1, 0, n - 1, l, r); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> rng(n + 1);
  std::vector<int> b;
  while (m--) {
    int i, l, r; std::cin >> i >> l >> r;
    b.emplace_back(l);
    b.emplace_back(r);
    rng[i].emplace_back(l, r);
  }
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  for (auto &u: rng) for (auto &[l, r]: u)
    l = std::lower_bound(b.begin(), b.end(), l) - b.begin(),
    r = std::lower_bound(b.begin(), b.end(), r) - b.begin();
  Segtree t(b.size());
  std::vector<int> dp(n + 1), par(n + 1);
  int add = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = i - 1;
    for (auto [l, r]: rng[i]) {
      auto got = t.get(l, r);
      if (chmin(dp[i], got.min + add)) par[i] = got.idx;
    }
    add++;
    for (auto [l, r]: rng[i]) t.update(l, r, dp[i] - add, i);
  }
  for (int i = 1; i <= n; ++i) dp[i] += n - i;
  int res = *std::min_element(dp.begin() + 1, dp.end());
  std::vector<bool> used(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) if (dp[i] == res) {
    for (int j = i; j; j = par[j]) used[j] = true, cnt++;
    break;
  }
  assert(n - cnt == res);
  std::cout << res << '\n';
//  std::vector<int> ch;
//  for (int i = 1; i <= n; ++i) if (used[i]) ch.emplace_back(i);
//  Segtree tt(b.size());
//  bool flag = true;
//  for (auto [l, r]: rng[ch[0]]) tt.update(l, 0, ch[0]), tt.update(r, 0, ch[0]);
//  for (int i = 1; i < ch.size(); ++i) {
//    bool fl = false;
//    for (auto [l, r]: rng[ch[i]]) {
//      auto got = tt.get(l, r);
//      if (got.idx != -1) fl = true;
//    }
//    if (!fl) {
//      flag = false;
//      break;
//    }
//    for (auto [l, r]: rng[ch[i]]) tt.update(l, 0, ch[i]), tt.update(r, 0, ch[i]);
//  }
//  assert(flag);
  for (int i = 1; i <= n; ++i) if (!used[i]) std::cout << i << ' ';
  std::cout << '\n';
  return 0;
}
