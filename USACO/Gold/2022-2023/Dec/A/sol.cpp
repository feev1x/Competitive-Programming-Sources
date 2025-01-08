/**
 *    author:  feev1x
 *    created: 03.01.2025 10:17:37
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, a, b; std::cin >> n >> a >> b;
  std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1, -INF));
  std::vector<int> p(n), c(n), x(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i] >> c[i] >> x[i];
  }
  dp[a][b] = 0;
  for (int k = 0; k < n; ++k) {
    auto new_dp = dp;
    for (int i = 0; i <= a; ++i) {
      for (int j = 0; j <= b - x[k]; ++j) {
        max_self(new_dp[i][j], );
      }
    }
  }
  return 0;
}
