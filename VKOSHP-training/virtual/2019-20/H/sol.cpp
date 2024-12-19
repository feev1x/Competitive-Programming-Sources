/**
 *    author:  feev1x
 *    created: 09.12.2024 09:58:11
**/
#include <bits/stdc++.h>

using i64 = long long;

inline i64 binpow(i64 a, int n) {
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
  i64 a, b; scanf("%lld%lld", &a, &b);
  int mod = a % 9;
  std::vector<std::string> ans;
  for (int i = 0; i < mod; ++i) {
    int lg = std::floor(std::log10(a));
    a += binpow(10, lg) * 9;
    ans.emplace_back("+ " + std::to_string(binpow(10, lg)));
    ans.emplace_back("- 1");
    a %= binpow(10, lg + 1);
  }
  i64 c = b;
  int cnt = 0;
  while (c < a) {
    int lg = std::floor(std::log10(c)) + 1;
    c += binpow(10, lg);
    cnt++;
  }
  std::string s = std::to_string(c);
  mod = 0;
  for (int i = 0; i < s.size(); ++i) {
    mod += s[i] - '0';
  }
  mod %= 9;
  mod = 9 - mod;
  mod %= 9;
  while (mod--) {
    int lg = std::floor(std::log10(c)) + 1;
    c += binpow(10, lg);
    cnt++;
  }
  if (c > a) {
    ans.emplace_back("+ " + std::to_string((c - a) / 9));
  }
  if (cnt) {
    ans.emplace_back("- " + std::to_string(cnt));
  }
  if (ans.size() > 1000) {
    printf("Broken\n");
  } else {
    printf("Stable\n%d\n", (int)ans.size());
    for (auto u: ans) {
      printf("%s\n", u.c_str());
    }
  }
  return 0;
}
