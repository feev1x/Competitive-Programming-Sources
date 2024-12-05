/**
 *    author:  feev1x
 *    created: 23.11.2024 13:47:01
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 1e9;

inline void min_self(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  std::freopen("marathon.in", "r", stdin);
  std::freopen("marathon.out", "w", stdout);
  int n, k; scanf("%d%d", &n, &k);
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  auto Dis = [&](int i, int j) {
    return std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
  };
  std::vector dp(n, std::vector<int>(k + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      int skip = i - j - 1;
      for (int sk = 0; sk + skip <= k; ++sk) {
        min_self(dp[i][sk + skip], dp[j][sk] + Dis(i, j));
      }
    }
  }
  printf("%d\n", *std::min_element(dp[n - 1].begin(), dp[n - 1].end()));
  return 0;
}
