/**
 *    author:  feev1x
 *    created: 21.11.2024 14:34:55
**/
#include <bits/stdc++.h>

using i64 = long long;
using u128 = unsigned __int128;

constexpr int SZ = 100;

char S[SZ];

std::string hex(u128 n) {
  std::string s;
  while (n > 0) {
    int x = n % 16;
    if (x > 9) {
      x -= 10;
      s += char(x + 'a');
    } else {
      s += char(x + '0');
    }
    n /= 16;
  }
  std::reverse(s.begin(), s.end());
  if (s.empty()) s = "0";
  return s;
}

u128 dec(std::string s) {
  u128 n = 0;
  std::reverse(s.begin(), s.end());
  u128 pw = 1;
  for (int i = 0; i < s.size(); ++i) {
    u128 num;
    if (std::isdigit(s[i])) {
      num = s[i] - '0';
    } else {
      num = 10 + s[i] - 'a';
    }
    n += pw * num;
    pw *= 16;
  }
  return n;
}

u128 binpow(u128 a, u128 n, u128 mod) {
  u128 res = 1;
  a %= mod;
  while (n) {
    if (n & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

u128 sqrt(u128 n) {
  if (n <= 1) return n;
  u128 y = n / 2;
  while (y > n / y) {
    y = (n / y + y) / 2;
  }
  return y;
}

bool check(u128 n, u128 a, u128 d, int s) {
  u128 x = binpow(a, d, n);
  if (x == 1 || x == n - 1) {
    return false;
  }
  for (int r = 1; r < s; ++r) {
    x = x * x % n;
    if (x == n - 1) {
      return false;
    }
  }
  return true;
}

bool isprime(u128 n, int iter = 40) {
  if (n < 4) {
    return n == 2 || n == 3;
  }
  int s = 0;
  u128 d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  for (int i = 0; i < iter; ++i) {
    u128 a = 2 + std::rand() % (n - 3);
    if (check(n, a, d, s)) {
      return false;
    }
  }
  return true;
}

u128 gcd(u128 a, u128 b) {
  if (a > b) {
    std::swap(a, b);
  }
  return a == 0 ? b : gcd(b % a, a);
}

void Solve(u128 n, int k) {
  u128 a = sqrt(n);
  std::set<u128> divs;
  while (divs.size() < k) {
    a++;
    u128 b2 = a * a - n;
    u128 b = sqrt(b2);
    if (b * b == b2) {
      divs.emplace(a - b);
      divs.emplace(a + b);
    }
  }
  std::set<u128> ans;
  for (auto u: divs) {
    for (auto v: divs) {
      u128 gcd_ = gcd(u, v);
      if (isprime(gcd_)) {
        ans.emplace(gcd_);
      }
    }
  }
  for (auto u: ans) {
    printf("%s\n", hex(u).c_str());
  }
}

int main() {
  int b, k; scanf("%d%d", &b, &k);
  scanf("%s", S);
  std::string s = S;
  Solve(dec(s), k);
  return 0;
}
