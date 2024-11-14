/**
 *    author:  feev1x
 *    created: 13.11.2024 15:55:45
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
//  std::freopen("k.in", "r", stdin);
//  std::freopen("K.out", "w", stdout);
  int n, k, s; scanf("%d%d%d", &n, &k, &s);
  std::vector<int> q(n);
  for (auto &u: q) {
    scanf("%d", &u);
  }
  if (s > n * (n - 1) / 2) {
    std::sort(q.begin(), q.end());
    printf("%d\n", std::accumulate(q.begin(), q.begin() + k, 0));
    return 0;
  }
  std::vector dp(k + 1, std::vector<int>(s + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    auto new_dp = dp;
    for (int j = 1; j <= std::min(i, k); ++j) {
      for (int ops = i - j; ops <= s; ++ops) {
        min_self(new_dp[j][ops], dp[j - 1][ops - i + j] + q[i - 1]);
      }
    }
    dp = new_dp;
  }
  printf("%d\n", *min_element(dp[k].begin(), dp[k].end()));
  return 0;
}
