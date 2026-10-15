#include <bits/stdc++.h>

#define int int64_t

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  if (k <= 1e6) {
    while (k--) n = n + (n % 10);
    std::cout << n << '\n';
    return 0;
  }
  std::vector<bool> used(10);
  used[n % 10] = true;
  int sz = 1, d = ((n % 10) * 2) % 10, sum = n % 10;
  while (!used[d]) {
    used[d] = true;
    sz++;
    sum += d;
    d = (d * 2) % 10;
  }
  while (n % 10 != d) sz--, sum -= n % 10, n = n + (n % 10), --k;
  n += sum * (k / sz);
  k %= sz;
  while (k--) n = n + (n % 10);
  std::cout << n << '\n';
  return 0;
}
