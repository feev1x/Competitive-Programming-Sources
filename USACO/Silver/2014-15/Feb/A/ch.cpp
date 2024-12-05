/**
 *    author:  feev1x
 *    created: 28.11.2024 14:26:59
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e6 + 1;

char S[MXSZ];

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
  Hash(std::string s, int _p1, int _p2, int _p3, int _mod1, int _mod2, int _mod3)
      : n(s.size()), p{_p1, _p2, _p3}, mod{_mod1, _mod2, _mod3} {
    for (int i = 0; i < 3; ++i) {
      h[i].resize(n + 1);
      pow_p[i].resize(n + 1);
      pow_p[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        pow_p[j][i] = mul(pow_p[j][i - 1], p[j], mod[j]);
        h[j][i] = add(h[j][i - 1], mul(s[i - 1], pow_p[j][i], mod[j]), mod[j]);
      }
    }
  }
  inline int hash(int l, int r, int i) {
    int res = sub(h[i][r], h[i][l - 1], mod[i]); 
    res = mul(res, pow_p[i][n - l], mod[i]);
    return res;
  }
  inline std::tuple<int, int, int> hash(int l, int r) {
    return {hash(l, r, 0), hash(l, r, 1), hash(l, r, 2)};
  }
  inline void pop_back() {
    for (int i = 0; i < 3; ++i) {
      pow_p[i].pop_back();
      h[i].pop_back();
    }
    n--;
  }
  inline void emplace_back(char c) {
    assert(pow_p[0].size());
    for (int i = 0; i < 3; ++i) {
      int j = pow_p[i].size();
      j--;
      pow_p[i].emplace_back(mul(pow_p[i][j], p[i], mod[i]));
      h[i].emplace_back(add(h[i][j], mul(c, pow_p[i][j + 1], mod[i]), mod[i]));
    }
    n++;
  }
};

int main() {
  scanf("%s", S);
  std::string s = S;
  scanf("%s", S);
  std::string t = S;
  int p1 = 31, p2 = 37, p3 = 41;
  int mod1 = 1e9 + 7, mod2 = 1e9 + 9, mod3 = 998244353;
  Hash h1("", p1, p2, p3, mod1, mod2, mod3), h2(t, p1, p2, p3, mod1, mod2, mod3);
  int n = s.size();
  std::string str;
  for (int i = n - 1; i >= 0; --i) {
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
  std::reverse(str.begin(), str.end());
  printf("%s\n", str.c_str());
  return 0;
}

