/**
 *    author:  feev1x
 *    created: 07.12.2024 19:12:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 n; scanf("%lld", &n);
  i64 m = n;
  n = std::sqrt(n);
  if (n + 1 < m) {
    n++;
  }
  std::vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  std::vector<i64> prm;
  for (i64 i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prm.emplace_back(i);
      for (i64 j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  n = m;
  int cnt = 0;
  for (auto u: prm) {
    i64 num = 1;
    for (int j = 0; j < 8; ++j) {
      num *= u;
      if (num > n) {
        break;
      }
    }
    if (num > n) {
      break;
    }
    cnt++;
  }
  for (int i = 0; i < prm.size(); ++i) {
    bool flag = false;
    for (int j = i + 1; j < prm.size(); ++j) {
      if (prm[i] * prm[i] * prm[j] * prm[j] > n) {
        if (j == i + 1) {
          flag = true;
        }
        break;
      }
      cnt++;
    }
    if (flag) {
      break;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
