/**
 *    author:  feev1x
 *    created: 06.01.2025 10:47:02
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7, INF = 1e9, N = 1e6 + 5;

int fac[N];

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

inline int Fac(int n) {
  if (n == 0) {
    return 1;
  }
  if (fac[n]) {
    return fac[n];
  }
  return fac[n] = mul(Fac(n - 1), n);
}

inline int divide(int a, int b) {
  return mul(a, binpow(b, MOD - 2));
}

inline int C(int n, int k) {
  return divide(Fac(n), mul(Fac(k), Fac(n - k)));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  int res = 1;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    b[i] = a[i] / 2;
  }
  for (int i = 1; i < n; ++i) {
    res = mul(res, b[i - 1] >= b[i] ? C(b[i - 1], b[i]) : C(b[i] - 1, b[i - 1] - 1));
  }
  std::cout << res << '\n';
  return 0;
}
