#include <bits/stdc++.h>

struct Bit {
  std::vector<int> p;
  int n;
  Bit(int n) : n(n) { p.resize(n + 1); }
  inline void update(int r, int x) { for (; r <= n; r += r & -r) p[r] += x; }
  inline int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) res += p[r];
    return res;
  }
  inline int get(int l, int r) { return get(r) - get(l - 1); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> c(n), sub(n), tin(n), tout(n), subp(n), par(n);
  std::vector<std::vector<int>> g(n), col(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i], col[--c[i]].emplace_back(i);
  for (int i = 1; i < n; ++i) {
    int a, b; std::cin >> a >> b;
    g[--a].emplace_back(--b);
    g[b].emplace_back(a);
  }
  int _t = 0;
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    par[v] = p;
    sub[v] = 1;
    subp[v] = 1;
    tin[v] = ++_t; for (auto to: g[v]) if (to != p) {
      self(self, to, v);
      sub[v] += sub[to];
      subp[v] += subp[to];
    }
    tout[v] = ++_t;
  }; Dfs(Dfs, 0, 0);
  Bit bit(_t);
  for (int i = 0; i < n; ++i) {
    std::sort(col[i].begin(), col[i].end(), [&](int i, int j) {
      return sub[i] < sub[j];
    });
    int64_t res = 0, sum = 0, sam = 0;
    std::vector<int> vs;
    for (auto v: col[i]) {
      sub[v] -= bit.get(tin[v], tout[v]);
      for (auto to: g[v]) if (to != par[v]) {
        subp[to] -= bit.get(tin[to], tout[to]);
        vs.emplace_back(to);
        res += subp[to] * 1LL * (n - subp[to]);
      }
      res += (n - sub[v] + 1);
      sum += sub[v];
      bit.update(tin[v], sub[v]);
    }
    for (auto v: vs) sam += subp[v] * 1LL * (sum - subp[v] - 1);
    for (auto v: col[i]) sam += (sum - sub[v]);
    res -= sam / 2;
    for (auto v: col[i]) bit.update(tin[v], -sub[v]);
    std::cout << res << '\n';
  }
  return 0;
}
