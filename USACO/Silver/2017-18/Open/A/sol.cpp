/**
 *    author:  feev1x
 *    created: 20.12.2024 16:00:20
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Bit {
  std::vector<int> p;
  int n;
  Bit(int _n) : n(_n) {
    p.resize(n + 1);
  }
  inline void modify(int r) {
    for (; r <= n; r += r & -r) {
      p[r]++;
    }
  }
  inline int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) {
      res += p[r];
    }
    return res;
  }
};

int main() {
//  std::freopen("sort.in", "r", stdin);
//  std::freopen("sort.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) {
    std::cin >> u;
  }
  auto b = a;
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  for (auto &u: a) {
    u = std::lower_bound(b.begin(), b.end(), u) - b.begin() + 1;
    u = n - u + 1;
  }
  i64 res = 0;
  Bit bit(n);
  for (auto u: a) {
    res += bit.get(u - 1);
    bit.modify(u);
  }
  std::cout << res << '\n';
  return 0;
}
