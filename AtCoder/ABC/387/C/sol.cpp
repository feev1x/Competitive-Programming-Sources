/**
 *    author:  feev1x
 *    created: 04.01.2025 18:04:12
**/
#include <bits/stdc++.h>

using i64 = long long;

inline i64 binpow(i64 a, int n) {
  if (a == 0) {
    return 0ll;
  }
  i64 res = 1;
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  i64 l, r; std::cin >> l >> r;  
  auto Count = [&](i64 num) {
    std::string s = std::to_string(num);
    if (s.size() == 1) {
      return 0ll;
    }
    i64 res = 0;
    for (int sz = 2; sz < s.size(); ++sz) {
      for (int f = 1; f <= 9; ++f) {
        res += binpow(f, sz - 1);
      }
    }
    int n = s.size();
    for (int f = 1; f < s[0] - '0'; ++f) {
      res += binpow(f, n - 1);
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] >= s[0]) {
        for (int f = 0; f < s[0] - '0'; ++f) {
          res += binpow(s[0] - '0', n - i - 1);
        }
        break;
      }
      for (int f = 0; f < s[i] - '0'; ++f) {
        res += binpow(s[0] - '0', n - i - 1);
      }
      if (i == n - 1) {
        res++;
      }
    }
    return res;
  };
  std::cout << Count(r) - Count(l - 1) << '\n';
  return 0;
}
