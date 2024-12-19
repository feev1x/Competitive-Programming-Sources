/**
 *    author:  feev1x
 *    created: 06.12.2024 10:08:08
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
  return (i64)a * b % MOD;
}

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

struct Bit {
  std::vector<int> p;
  int n;
  Bit(int _n) : n(_n), p(_n + 1) {}
  inline void modify(int r, int x) {
    for (; r <= n; r += r & -r) {
      add_self(p[r], x);
    }
  }
  inline int get(int r) {
    int res = 0;
    for (; r >= 1; r -= r & -r) {
      add_self(res, p[r]);
    }
    return res;
  }
};

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  std::map<int, int> val;
  int nw = 1;
  for (auto &u: a) {
    scanf("%d", &u);
  }
  auto b = a;
  std::sort(b.begin(), b.end());
  for (auto u: b) {
    if (!val[u]) {
      val[u] = nw++;
    }
  }
  for (auto &u: a) {
    u = val[u];
  }
  Bit bit(nw + 1);
  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = bit.get(a[i] - 1) + 1;
    if (dp[i] >= MOD) {
      dp[i] -= MOD;
    }
    bit.modify(a[i], dp[i]);
  }
  Bit bi(nw + 1);
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {
    int u = bi.get(a[i] - 1) + 1;
    if (u >= MOD) {
      u -= MOD;
    }
    add_self(res, mul(dp[i], u));
    bi.modify(a[i], u);
  }
  printf("%d\n", res);
  return 0;
}
