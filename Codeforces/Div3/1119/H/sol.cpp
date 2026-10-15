#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) { return a * 1LL * b % MOD; }
inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

inline int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

struct Dsu {
  std::vector<int> sz, p;
  int n;
  Dsu(int n) : n(n) {
    sz.assign(n, 1);
    p.resize(n);
    std::iota(p.begin(), p.end(), 0);
  }
  inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
  inline void unite(int u, int v) {
    u = get(u), v = get(v);
    if (u != v) {
      if (sz[u] > sz[v]) std::swap(u, v);
      sz[v] += sz[u];
      p[u] = v;
    }
  }
};

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> b(n), val(n + 1);
  for (auto &u: b) std::cin >> u;
  for (int i = 0; i < n; ++i) if (b[i] > 0) {
    ++val[std::max(0, i - b[i] + 1)];
    --val[std::min(n, i + b[i])];
  }
  for (int i = 1; i < n; ++i) val[i] += val[i - 1];
  bool flag = true;
  for (int i = 0; i < n; ++i) if (b[i] != -1) {
    if (b[i] == 0) {
      if (val[i] > 0) return std::cout << "0\n", void();
      val[i] = -1;
    } else {
      if (i - b[i] < 0 || val[i - b[i]] > 0) {
        if (i + b[i] >= n || val[i + b[i]] > 0) return std::cout << "0\n", void();
        val[i + b[i]] = -1;
      } else if (i + b[i] >= n || val[i + b[i]] > 0) val[i - b[i]] = -1;
      else {
        
      }
    }
  }
  Dsu d(n);
  for (int i = 0; i < n; ++i) if (b[i] > 0)
    if (!(i - b[i] < 0 || val[i - b[i]]) && !(i + b[i] >= n || val[i + b[i]]))
      d.unite(i - b[i], i + b[i]);
  std::vector dp(n + 2, std::vector<int>(2));
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n + 1; ++i) {
    add_self(dp[i][0], dp[i - 1][1]);
    add_self(dp[i][1], dp[i - 1][1]);
    add_self(dp[i][1], dp[i - 1][0]);
  }
  int res = 1;
  std::vector<bool> used(n);
  for (int i = 0; i < n; ++i) if (!val[i] && !used[d.get(i)]) {
    used[d.get(i)] = true;
    res = mul(res, dp[d.sz[d.get(i)] + 1][1]);
  }
  if (*std::max_element(b.begin(), b.end()) == -1) add_self(res, -1);
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
