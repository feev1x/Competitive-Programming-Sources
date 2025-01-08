/**
 *    author:  feev1x
 *    created: 20.12.2024 21:56:58
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

inline void min_self(i64 &a, i64 b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, m; i64 k; std::cin >> n >> m >> k;
    std::vector a(n + 1, std::vector<i64>(m + 1));
    std::vector take(n + 2, std::vector<i64>(m + 1, INF));
    std::vector dp(n + 2, std::vector(m + 2, std::vector<i64>(m + 1, INF)));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::cin >> a[i][j];
      }
    }
    take[1][1] = 0;
    dp[1][1][0] = a[1][1];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int c = 0; c < m; ++c) {
          min_self(dp[i][j][c], take[i][j] + k * c + a[i][(j + c - 1) % m + 1]);
          min_self(take[i + 1][j], dp[i][j][c]);
          min_self(dp[i][j + 1][c], dp[i][j][c] + a[i][(j + c) % m + 1]);
        }
      }
    }
    i64 res = INF;
    for (int c = 0; c < m; ++c) {
      min_self(res, dp[n][m][c]);
    }
    std::cout << res << '\n';
  }
  return 0;
}
