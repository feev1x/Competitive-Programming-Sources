/**
 *    author:  feev1x
 *    created: 18.11.2024 17:06:44
**/
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned i64;

constexpr u64 P1 = 190370459ull, P2 = 244688687ull, N1 = 1ull;
constexpr u64 MOD1 = 927310585444535321ull;
constexpr u64 MOD2 = 985762081219264589ull;

inline void sub_self(u64 &a, u64 b, const u64 MOD) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline void add_self(u64 &a, u64 b, const u64 MOD) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

u64 binpow(u64 a, u64 n, const u64 MOD) {
  u64 res = 1;
  while (n) {
    if (n & N1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    n >>= 1;
  }
  return res;
}

int main() {
  int tt, n; scanf("%d%d", &tt, &n);
  int sz = std::min(10000, n);
  std::vector<u64> pow_p1(n + 1, 1);
  std::vector<u64> pow_p2(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    pow_p1[i] = (pow_p1[i - 1] * P1) % MOD1;
    pow_p2[i] = (pow_p2[i - 1] * P2) % MOD2;
  }
  if (tt == 1) {
    std::vector<int> p(n);
    std::string s;
    u64 hash1 = 0, hash2 = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p[i]);
      hash1 = (hash1 + p[i] * pow_p1[i + 1]) % MOD1;
      hash2 = (hash2 + p[i] * pow_p2[i + 1]) % MOD2;
    }
    for (u64 i = 0; i < 100; ++i) {
      if (hash1 >> i & N1) {
        s += "1";
      } else {
        s += "0";
      }
    }
    for (u64 i = 0; i < 100; ++i) {
      if (hash2 >> i & N1) {
        s += "1";
      } else {
        s += "0";
      }
    }
    while (s.size() > 200) n++;
    printf("%s\n", s.c_str());
  } else {
    std::vector<int> q(n), p;
    for (auto &u: q) {
      scanf("%d", &u);
    }
    char S[300]; scanf("%s", S);
    std::string s = S;
    u64 thash1 = 0, thash2 = 0, hash1 = 0, hash2 = 0;
    for (u64 i = 0; i < 100; ++i) {
      if (s[i] == '1') {
        add_self(thash1, binpow(2, i, MOD1), MOD1);
      }
    }
    for (u64 i = 0; i < 100; ++i) {
      if (s[i + 100] == '1') {
        add_self(thash2, binpow(2, i, MOD2), MOD2);
      }
    }
    for (int i = 0; i < n; ++i) {
      hash1 = (hash1 + q[i] * pow_p1[i + 1]) % MOD1;
      hash2 = (hash2 + q[i] * pow_p2[i + 1]) % MOD2;
    }
    for (int i = 0; i < sz; ++i) {
      for (int j = 1; j < sz; ++j) {
        u64 sw_hash1 = hash1, sw_hash2 = hash2;
        sw_hash1 = (sw_hash1 + MOD1 - (q[i] * pow_p1[i + 1]) % MOD1) % MOD1;
        sw_hash1 = (sw_hash1 + (q[j] * pow_p1[i + 1]) % MOD1) % MOD1;
        sw_hash1 = (sw_hash1 + (q[i] * pow_p1[j + 1]) % MOD1) % MOD1;
        sw_hash1 = (sw_hash1 + MOD1 - (q[j] * pow_p1[j + 1]) % MOD1) % MOD1;
        sw_hash2 = (sw_hash2 + MOD2 - (q[i] * pow_p2[i + 1]) % MOD2) % MOD2;
        sw_hash2 = (sw_hash2 + (q[j] * pow_p2[i + 1]) % MOD2) % MOD2;
        sw_hash2 = (sw_hash2 + (q[i] * pow_p2[j + 1]) % MOD2) % MOD2;
        sw_hash2 = (sw_hash2 + MOD2 - (q[j] * pow_p2[j + 1]) % MOD2) % MOD2;
        if (sw_hash1 == thash1 && sw_hash2 == thash2) {
          std::swap(q[i], q[j]);
          p = q;
        }
      }
    }
    if (p.empty()) {
      for (int i = sz; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          u64 sw_hash1 = hash1, sw_hash2 = hash2;
          sw_hash1 = (sw_hash1 + MOD1 - (q[i] * pow_p1[i + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + (q[j] * pow_p1[i + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + (q[i] * pow_p1[j + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + MOD1 - (q[j] * pow_p1[j + 1]) % MOD1) % MOD1;
          sw_hash2 = (sw_hash2 + MOD2 - (q[i] * pow_p2[i + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + (q[j] * pow_p2[i + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + (q[i] * pow_p2[j + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + MOD2 - (q[j] * pow_p2[j + 1]) % MOD2) % MOD2;
          if (sw_hash1 == thash1 && sw_hash2 == thash2) {
            std::swap(q[i], q[j]);
            p = q;
          }
        }
      }
    }
    if (p.empty()) {
      for (int i = 0; i < n; ++i) {
        for (int j = sz; j < n; ++j) {
          u64 sw_hash1 = hash1, sw_hash2 = hash2;
          sw_hash1 = (sw_hash1 + MOD1 - (q[i] * pow_p1[i + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + (q[j] * pow_p1[i + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + (q[i] * pow_p1[j + 1]) % MOD1) % MOD1;
          sw_hash1 = (sw_hash1 + MOD1 - (q[j] * pow_p1[j + 1]) % MOD1) % MOD1;
          sw_hash2 = (sw_hash2 + MOD2 - (q[i] * pow_p2[i + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + (q[j] * pow_p2[i + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + (q[i] * pow_p2[j + 1]) % MOD2) % MOD2;
          sw_hash2 = (sw_hash2 + MOD2 - (q[j] * pow_p2[j + 1]) % MOD2) % MOD2;
          if (sw_hash1 == thash1 && sw_hash2 == thash2) {
            std::swap(q[i], q[j]);
            p = q;
          }
        }
      }
    }
    for (auto u: p) {
      printf("%d ", u);
    }
    printf("\n");
  }
  return 0;
}
