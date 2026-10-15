#include <bits/stdc++.h>

constexpr int N = 32;

inline int get(int n, int k) {
  std::vector dp(N, std::vector(N, std::vector<int>(2)));
  dp[N - 1][0][1] = 1;
  for (int i = N - 1; i > 0; --i) {
    for (int j = 0; j < N; ++j) {
      if (dp[i][j][0]) {
        dp[i - 1][j][0] += dp[i][j][0];
        dp[i - 1][j + 1][0] += dp[i][j][0];
      }
      if (dp[i][j][1]) {
        if (n >> (i - 1) & 1) {
          dp[i - 1][j][0] += dp[i][j][1];
          dp[i - 1][j + 1][1] += dp[i][j][1];
        } else dp[i - 1][j][1] += dp[i][j][1];
      }
    }
  }
  return dp[0][k][0] + dp[0][k][1];
}

inline void solve() {
  int a, b, k; std::cin >> a >> b >> k;
  std::cout << get(b, k) - get(a - 1, k) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
