#include <bits/stdc++.h>

struct Bit {
  std::vector<int> p;
  int n;
  Bit() {}
  Bit(int n) : n(n) { p.resize(n + 1); }
  inline void update(int r, int x) { for (; r <= n; r += r & -r) p[r] += x; }
  inline int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) res += p[r];
    return res;
  }
};

struct Hld {
  std::vector<std::vector<int>> g;
  std::vector<int> sz, heavy, idx, head, p, d;
  int n, timer = 0, m;
  std::set<std::pair<int, int>> st;
  Bit bit;
  inline void dfs(int v) {
    sz[v] = 1;
    d[v] = d[p[v]] + 1;
    for (auto to: g[v]) if (to != p[v]) {
      p[to] = v;
      dfs(to);
      sz[v] += sz[to];
      if (sz[heavy[v]] < sz[to]) heavy[v] = to;
    }
  }
  inline void dec(int v) {
    idx[v] = ++timer;
    if (heavy[v]) head[heavy[v]] = head[v], dec(heavy[v]);
    for (auto to: g[v]) if (to != p[v] && to != heavy[v]) dec(to);
  }
  Hld(std::vector<std::vector<int>> g, int m) : g(g), n(g.size() - 1), m(m) {
    sz.resize(n + 1);
    heavy.resize(n + 1);
    idx.resize(n + 1);
    head.resize(n + 1);
    d.resize(n + 1);
    std::iota(head.begin(), head.end(), 0);
    p.resize(n + 1);
    dfs(1), dec(1);
    bit = Bit(m + 1);
    bit.update(m + 1, timer);
    st.emplace(1, m + 1);
    st.emplace(timer + 1, m + 1);
  }
  inline void set(int l, int r, int x) {
    if (l > r) return;
    auto it = --st.upper_bound({l, m + 5});
//    std::cerr << l << ' ' << r << ' ' << x << ' ' << bit.get(4) << ' ' << it->first << '\n';
    auto it2 = it;
    if (it2->first < l) ++it2;
    bool flag = false;
    while (it->first <= r) {
      int val = it->second;
      int L = std::max(l, it->first);
      int R = std::min(r + 1, (++it)->first);
//      std::cerr << L << ' ' << R << ' ' << val << ' ' << x << " SUKA" << '\n';
      bit.update(val, -(R - L));
      bit.update(x, R - L);
    }
    if (it->first != r + 1) st.emplace(r + 1, prev(it)->second), it = st.lower_bound({r + 1, 0});
    if (it2->first <= r) st.erase(it2, it);
    st.emplace(l, x);
  }
  inline void update(int u, int v, int x) {
    while (head[u] != head[v]) {
      if (d[head[u]] < d[head[v]]) std::swap(u, v);
      set(idx[head[u]], idx[u], x);
      u = p[head[u]];
    }
    if (idx[u] > idx[v]) std::swap(u, v);
    set(idx[u] + 1, idx[v], x);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<int> c(m + 1);
  for (int i = 1; i <= m; ++i) std::cin >> c[i];
  std::vector<int> lq(q), rq(q), ans(q);
  std::vector<std::vector<int>> qq(m + 1);
  for (int i = 0; i < q; ++i) {
    std::cin >> lq[i] >> rq[i];
    qq[lq[i]].emplace_back(i);
  }
  Hld hld(g, m);
  for (int l = m; l >= 1; --l) {
    for (auto i: qq[l]) ans[i] = hld.bit.get(rq[i]) + 1;
    if (l != 1) hld.update(c[l - 1], c[l], l);
  }
  for (int i = 0; i < q; ++i) std::cout << ans[i] << '\n';
  return 0;
}
