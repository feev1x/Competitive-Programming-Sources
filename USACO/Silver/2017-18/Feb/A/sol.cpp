/**
 *    author:  feev1x
 *    created: 19.12.2024 11:37:15
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("reststops.in", "r", stdin);
  std::freopen("reststops.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int l, n, rf, rb; std::cin >> l >> n >> rf >> rb;
  std::vector<int> x(n), c(n);
  std::set<std::pair<i64, int>> st;
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> c[i];
    st.emplace(-c[i], x[i]);
  }
  i64 res = 0;
  int start = 0;
  for (auto [cost, pos]: st) {
    if (pos <= start) {
      continue;
    }
    cost = -cost;
    i64 df = pos - start;
    res += cost * (df * rf - df * rb);
    start = pos;
  }
  std::cout << res << '\n';
  return 0;
}
