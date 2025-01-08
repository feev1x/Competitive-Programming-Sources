/**
 *    author:  feev1x
 *    created: 08.01.2025 10:35:24
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

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
  return mul(a, binpow(b, MOD - 2));
}

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::string> s(m);
  for (auto &u: s) {
    std::cin >> u;
  }
  std::vector<int> fac(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fac[i] = mul(fac[i - 1], i);
  }
  auto P = [&](int n, int k) {
    return divide(fac[n], fac[n - k]);
  };
  auto C = [&](int n, int k) {
    return divide(fac[n], mul(fac[k], fac[n - k]));
  };
  if (m == 1) {
    int cnt_e = count(s[0].begin(), s[0].end(), 'E');
    int cnt_h = n - cnt_e;
    int e = 0, h = 0;
    for (int i = 0; i <= n; ++i) {
      if (i <= cnt_e) {
        add_self(e, P(cnt_e, i));
      }
      if (i <= cnt_h) {
        add_self(h, P(cnt_h, i));
      }
    }
    std::cout << mul(e, h) - 1 << '\n';
  } else {
    std::vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](int i, int j) {
      for (int k = 0; k < m; ++k) {
        if (s[k][i] == s[k][j]) {
          continue;
        }
        return s[k][i] == 'E';
      }
    });

  }
  return 0;
}
