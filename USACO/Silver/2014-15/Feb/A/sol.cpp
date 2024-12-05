/**
 *    author:  feev1x
 *    created: 28.11.2024 14:26:59
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e6 + 1, N = 1e6;

char S[MXSZ];

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline bool isprime(int p) {
  for (int i = 2; i * i <= p; ++i) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}

inline int prime(int l, int r) {
  std::uniform_int_distribution<int> dist(l, r - 1);
  int p = dist(rng);
  while (!isprime(p)) {
    p--;
    if (p < l) p = dist(rng);
  }
  return p;
}

inline int mul(int a, int b, int mod) {
  return (i64)a * b % mod;
}

inline int add(int a, int b, int mod) {
  i64 res = (i64)a + b;
  if (res >= mod) {
    res -= mod;
  }
  return (int)res;
}

inline int sub(int a, int b, int mod) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

struct Hash {
  std::vector<int> h[3], pow_p[3];
  int n, p[3], mod[3];
  Hash(std::string s, std::vector<int> _p, std::vector<int> _mod) : n(s.size()), p{_p[0], _p[1], _p[2]}, mod{_mod[0], _mod[1], _mod[2]} {
    for (int i = 0; i < 3; ++i) {
      h[i].resize(n + 1);
      pow_p[i].resize(N + 1);
      pow_p[i][0] = 1;
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < 3; ++j) {
        pow_p[j][i] = mul(pow_p[j][i - 1], p[j], mod[j]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        h[j][i] = add(h[j][i - 1], mul(s[i - 1], pow_p[j][i], mod[j]), mod[j]);
      }
    }
  }
  inline int hash(int l, int r, int i) {
    int res = sub(h[i][r], h[i][l - 1], mod[i]); 
    res = mul(res, pow_p[i][N - l], mod[i]);
    return res;
  }
  inline std::tuple<int, int, int> hash(int l, int r) {
    return {hash(l, r, 0), hash(l, r, 1), hash(l, r, 2)};
  }
  inline void pop_back() {
    for (int i = 0; i < 3; ++i) {
      h[i].pop_back();
    }
    n--;
  }
  inline void emplace_back(char c) {
    for (int i = 0; i < 3; ++i) {
      int j = h[i].size();
      j--;
      h[i].emplace_back(add(h[i][j], mul(c, pow_p[i][j + 1], mod[i]), mod[i]));
    }
    n++;
  }
};

int main() {
  std::freopen("censor.in", "r", stdin);
  std::freopen("censor.out", "w", stdout);
  scanf("%s", S);
  std::string s = S;
  scanf("%s", S);
  std::string t = S;
  std::vector<int> p{prime(1e8, 2e8), prime(3e8, 4e8), prime(5e8, 6e8)}, mod{prime(1e9, 2e9), prime(1e9, 2e9), prime(1e9, 2e9)};
  Hash h1("", p, mod), h2(t, p, mod);
  int n = s.size();
  std::string str;
  for (int i = 0; i < n; ++i) {
    str += s[i];
    h1.emplace_back(s[i]);
    if (str.size() < t.size()) {
      continue;
    }
    int sz = str.size(), l = sz - (int)t.size() + 1;
    if (h1.hash(l, str.size()) == h2.hash(1, t.size())) {
      sz = t.size();
      while (sz--) {
        h1.pop_back();
        str.pop_back();
      }
    }
  }
  printf("%s\n", str.c_str());
  return 0;
}
