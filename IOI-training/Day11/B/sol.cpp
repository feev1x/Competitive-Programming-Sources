#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return a * 1LL * b % MOD; }

inline int binpow(int a, int n) {
  int res = 1;
  while (n) { 
    if (n & 1) res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

constexpr int R = 600;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i];
  std::vector<int> ans(m + 1), inv(m + 2);
  for (int i = 1; i <= m + 1; ++i) inv[i] = binpow(i, MOD - 2);
  int res = 1, cnt = 0;
  std::vector<std::vector<std::pair<int, int>>> pl(m + 2), pr(m + 2);
  auto o_l = l, o_r = r;
  for (int i = 0; i < n; ++i) {
    res = mul(res, r[i] - l[i] + 1);
    if ((o_l[i] + 1) / 2 != l[i]) pl[2].emplace_back((o_l[i] + 1) / 2, i);
    else if (l[i] - 1) pl[(o_l[i] + (l[i] - 1) - 1) / (l[i] - 1)].emplace_back(l[i] - 1, i);
    if (o_r[i] / 2 != r[i]) pr[2].emplace_back(o_r[i] / 2, i);
    else if (r[i]) pr[o_r[i] / r[i] + 1].emplace_back(r[i] - 1, i);
  }
  for (int g = 1; g <= m; ++g) {
    for (auto [x, i]: pr[g]) {
      if (r[i] - l[i] + 1 > 0) res = mul(res, inv[r[i] - l[i] + 1]);
      else --cnt;
      r[i] = x;
      if (o_r[i] / (g + 1) != r[i]) pr[g + 1].emplace_back(o_r[i] / (g + 1), i);
      else if (r[i]) pr[o_r[i] / r[i] + 1].emplace_back(r[i] - 1, i);
      if (r[i] - l[i] + 1 > 0) res = mul(res, r[i] - l[i] + 1);
      else ++cnt;
    }
    for (auto [x, i]: pl[g]) {
      if (r[i] - l[i] + 1 > 0) res = mul(res, inv[r[i] - l[i] + 1]);
      else --cnt;
      l[i] = x;
      if ((o_l[i] + g) / (g + 1) != l[i]) pl[g + 1].emplace_back((o_l[i] + g) / (g + 1), i);
      else if (l[i] - 1) pl[(o_l[i] + (l[i] - 1) - 1) / (l[i] - 1)].emplace_back(l[i] - 1, i);
      if (r[i] - l[i] + 1 > 0) res = mul(res, r[i] - l[i] + 1);
      else ++cnt;
    }
    ans[g] = (cnt ? 0 : res);
    std::vector<std::pair<int, int>>().swap(pr[g]);
    std::vector<std::pair<int, int>>().swap(pl[g]);
  }
  for (int g = m; g >= 1; --g)
    for (int i = 2; i * g <= m; ++i)
      add_self(ans[g], -ans[i * g]);
  for (int i = 1; i <= m; ++i) std::cout << ans[i] << " \n"[i == m];
  return 0;
}
