/**
 *    author:  feev1x
 *    created: 27.12.2024 09:13:26
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline int mul(int a, int b) {
  return (i64)a * b % MOD;
}

inline int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

inline int divide(int a, int b) {
  return (i64)a * binpow(b, MOD - 2) % MOD;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> p(n + 1), ch(n + 1), fac(n + 2);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
    fac[i] = mul(fac[i - 1], i);
  }
  fac[n + 1] = mul(fac[n], n + 1);
  std::vector<bool> used(n + 1);
  auto C = [&](int N, int K) {
    return divide(fac[N], mul(fac[K], fac[N - K]));
  };
  int res = 0;
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (used[i]) {
      continue;
    }
    int sz = 0;
    int u = i;
    while (!used[u]) {
      used[u] = true;
      u = p[u];
      sz++;
    }
    if (sz == 1) {
      add_self(res, mul(n, fac[n]));
      c++;
    } else if (sz % 2 == 0) {
      add_self(res, mul(C(n + 1, sz + 1), mul(fac[sz / 2], mul(fac[sz / 2], mul(fac[n - sz], 2)))));
    }
  }
  for (int k = 1; k < n; ++k) {
    add_self(res, mul(mul(fac[n - 2], mul(mul(n - k, n - k), n - c)), 2));
  }
  std::cout << res << '\n';
  return 0;
}
