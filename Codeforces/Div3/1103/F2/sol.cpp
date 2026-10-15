#include <bits/stdc++.h>

constexpr int N = 5e5 + 5, MOD = 1e9 + 7;
std::vector<int> pr[N];
bool inx[N];
int fac[N], inv[N], cnt[N];

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return 1LL * a * b % MOD; }

inline int binpow(int a, int n) {
  int res = 1;
  while (n) { if (n & 1) res = mul(res, a); a = mul(a, a), n >>= 1; }
  return res;
}

inline int C(int n, int k) { return mul(fac[n], mul(inv[k], inv[n - k])); }

inline void solve() {
  int n, x; std::cin >> n >> x;
  for (auto u: pr[x]) inx[u] = true;
  std::vector<int> a(n);
  int res = 1;
  for (auto &u: a) {
    std::cin >> u;
    for (auto v: pr[u]) {
      if (!inx[v]) res = mul(res, 2);
      else cnt[v]++;
    }
  }
  int cn = 0;
  for (int i = 0; i < pr[x].size(); ++i) {
    cn++;
    if (i + 1 < pr[x].size() && pr[x][i + 1] == pr[x][i]) continue;
    if (cnt[pr[x][i]] <= cn) { res = 0; break; }
    res = mul(res, C(cnt[pr[x][i]], cn + 1));
    cn = 0;
  }
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
  inv[N - 1] = binpow(fac[N - 1], MOD - 2);
  for (int i = N - 2; i > 0; --i) inv[i] = mul(inv[i + 1], i + 1);
  for (int i = 2; i < N; ++i) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        pr[i].emplace_back(j);
        for (auto u: pr[i / j]) pr[i].emplace_back(u);
        break;
      }
    }
    if (pr[i].empty()) pr[i].emplace_back(i);
  }
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
