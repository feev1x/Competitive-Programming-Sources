/**
 *    author:  feev1x
 *    created: 18.11.2024 09:17:31
**/
#include <bits/stdc++.h>

using i64 = long long;
using u128 = __int128;

constexpr u128 MOD = 1e9 + 7, MXANS = 1e25 + 5;

u128 gcd(u128 a, u128 b) {
  if (a > b) {
    std::swap(a, b);
  }
  return a == 0 ? b : gcd(b % a, a);
}

u128 lcm(u128 a, u128 b) {
  return a / gcd(a, b) * b;
}

u128 binpow(u128 a, u128 n) {
  u128 res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
      if (res < 0) {
        return std::numeric_limits<u128>::max();
      }
    }
    a *= a;
    n >>= 1;
  }
  if (res < 0) res = std::numeric_limits<u128>::max();
  return res;
}

inline void min_self(u128 &a, u128 b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  char S[13];
  std::string a, b, c;
  if (n) {
    scanf(" %s", S);
    a = S;
  }
  if (m) {
    scanf(" %s", S);
    b = S;
  }
  if (k) {
    scanf(" %s", S);
    c = S;
  }
  u128 d1 = 1, u1 = 0, u2 = 0;
  for (int i = 0; i < b.size(); ++i) {
    u1 = u1 * 10 + b[i] - '0';
  }
  u128 full = u1;
  for (int i = 0; i < c.size(); ++i) {
    u2 = u2 * 10 + c[i] - '0';
    full = full * 10 + c[i] - '0';
  }
  if (!c.empty()) {
    u1 = full - u1; 
    d1 = binpow(10, b.size()) * (binpow(10, c.size()) - 1);
  } else {
    d1 = binpow(10, b.size());
  }
  while (gcd(d1, u1) > 1) {
    u128 gc = gcd(d1, u1);
    d1 /= gc;
    u1 /= gc;
  }
  u128 t1 = d1;
  u128 mb = 1;
  for (u128 i = 2; i * i <= d1; ++i) {
    if (d1 % i == 0) {
      mb *= i;
      while (d1 % i == 0) {
        d1 /= i;
      }
    }
  }
  if (d1 > 1) {
    mb *= d1;
  }
  i64 res = std::min(mb, t1) % MOD;
  printf("%lld\n", res);
  return 0;
}

