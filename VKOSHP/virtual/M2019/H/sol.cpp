/**
 *    author:  feev1x
 *    created: 12.11.2024 10:17:34
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

u128 gcd(u128 a, u128 b) {
  if (a > b) {
    std::swap(a, b);
  }
  return a == 0 ? b : gcd(a, b % a);
}

u128 lcm(u128 a, u128 b) {
  return a / gcd(a, b) * b;
}

void scan(u128 &x) {
  u128 f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}

int main() {
  int n; scanf("%d", &n);
  std::vector<u128> a(n), gc(n);
  for (auto &u: a) {
    scan(u);
  }
  gc.back() = a.back();
  for (int i = n - 2; i >= 0; --i) {
    gc[i] = gcd(gc[i + 1], a[i]);
  }
  u128 lc = a[0];
  for (int i = 0; i < n; ++i) {
    lc = lcm(lc, a[i]);
    if (lc == a[i] && gc[i] == a[i]) {
      std::map<u128, bool> mp;
      for (int j = 0; j < i; ++j) {
        mp[a[i] / a[j]] = true;
      }
      bool flag = true;
      for (int j = i + 1; j < n; ++j) {
        if (mp[a[j] / a[i]]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        printf("%d\n", n - 1);
        exit(0);
      }
    }
  }
  printf("%d\n", n);
  return 0;
}
