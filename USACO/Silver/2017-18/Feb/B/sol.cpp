/**
 *    author:  feev1x
 *    created: 19.12.2024 14:33:53
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("snowboots.in", "r", stdin);
  std::freopen("snowboots.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, b; std::cin >> n >> b;
  std::vector<int> f(n), d(b + 1), s(b + 1);
  for (auto &u: f) {
    std::cin >> u;
  }
  for (int i = 1; i <= b; ++i) {
    std::cin >> s[i] >> d[i];
  }
  d[0] = 1;
  std::vector<int> dp(n + 1, b);
  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (dp[j] == -1) {
        continue;
      }
      for (int k = dp[j]; k < dp[i]; ++k) {
        if (s[k] >= f[j - 1] && s[k] >= f[i - 1] && i - j <= d[k]) {
          dp[i] = k;
          break;
        }
      }
    }
  }
  std::cout << dp[n] - 1 << '\n';
  return 0;
}
