#include <bits/stdc++.h>

struct Ss {
  std::vector<int> B, a, cnt, cc;
  std::stack<std::pair<int, int>> stk;
  int n, sq;
  Ss(int n) : n(n) {
    sq = sqrt(n);
    B.resize(n / sq + 1);
    a.resize(n + 1);
    cnt.resize(n + 1);
    cc.resize(n + 1);
  }
  inline void upd(int i, int x) {
    B[i / sq] += x;
    a[i] += x;
  }
  inline void update(int x, int i) {
    upd(x, -cnt[x]);
    cnt[x] += i;
    upd(x, cnt[x]);
    stk.emplace(x, i);
  }
  inline int get(int r) {
    int res = 0;
    for (int i = 0; i < r / sq; ++i) res += B[i];
    for (int i = r; i / sq == r / sq; --i) res += a[i];
    return res;
  }
  inline void fix() {
    while (stk.size()) stk.pop();
  }
  inline void rollback() {
    while (stk.size()) {
      auto [x, i] = stk.top(); stk.pop();
      upd(x, -cnt[x]);
      cnt[x] -= i;
      upd(x, cnt[x]);
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<int> x(n + 1), ans(q), tin(n + 1), tout(n + 1);
  std::vector<std::pair<int, int>> ar;
  for (int i = 1; i <= n; ++i) std::cin >> x[i];
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; std::cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  std::vector<std::tuple<int, int, int, int>> qq(q);
  int index = 0;
  int _t = 0;
  auto Dfs = [&](auto &&self, int v, int p) -> void {
    tin[v] = ++_t;
    ar.emplace(v);
    for (auto to: g[v]) if (to != p) self(self, to, v);
    tout[v] = ++_t;
    ar.emplace(v);
  }; Dfs(Dfs, 1, 1);
  int sq = sqrt(n);
  std::vector<std::vector<int>> B(_t / sq + 1);
  for (auto &[s, t, a, b]: qq) {
    std::cin >> s >> t >> a >> b;
    if (tout[s] > tin[t]) std::swap(s, t);
    B[tout[s] / sq].emplace_back(index);
    index++;
  }
  for (int b = 0; b <= _t / sq; ++b) {
    std::sort(B[b].begin(), B[b].end(), [&](int i, int j) {
      return tin[std::get<1>(qq[i])] < tin[std::get<1>(qq[j])];
    });
    int r = (b + 1) * sq;
    Ss st(n);
    for (auto i: B[b]) {
      while (r < tin[std::get<1>(qq[i])]) {
        st.update(
      }
    }
  }
  return 0;
}
