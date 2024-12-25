/**
 *    author:  feev1x
 *    created: 19.12.2024 09:47:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("rental.in", "r", stdin);
  std::freopen("rental.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, r; std::cin >> n >> m >> r;
  std::vector<int> c(n), q(m), p(m), a(r), pos(m);
  for (auto &u: c) {
    std::cin >> u;
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> q[i] >> p[i];
  }
  for (auto &u: a) {
    std::cin >> u;
  }
  std::iota(pos.begin(), pos.end(), 0); 
  std::sort(pos.begin(), pos.end(), [&](int i, int j) {
      return p[i] > p[j];
      });
  std::sort(a.begin(), a.end(), std::greater<>());
  std::sort(c.begin(), c.end());
  i64 res = 0, nw = 0, milk = accumulate(c.begin(), c.end(), 0ll);
  i64 sum_milk = 0, sum_cost = 0;
  for (int i = 0; i < m; ++i) {
    sum_milk += q[i];
    sum_cost += q[i] * p[i];
  }
  for (int i = 0, j = m - 1; i <= std::min(r, n); ++i) {
    while (sum_milk > milk) {
      sum_milk -= q[pos[j]];
      sum_cost -= p[pos[j]] * q[pos[j]];
      --j;
    }
    i64 cost = 0;
    if (j < m - 1) {
      cost = (milk - sum_milk) * p[pos[j + 1]];
    }
    res = std::max(res, nw + sum_cost + cost);
    if (i < r && i < n) {
      nw += a[i];
      milk -= c[i];
    }
  }
  std::cout << res << '\n';
  return 0;
}
