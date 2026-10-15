#include <bits/stdc++.h>

inline void solve() {
  int n, k; std::cin >> n >> k;
  std::vector<int> dp(n + 1);
  std::vector<std::vector<int>> dv(n + 1);
  for (int i = 2; i <= n; ++i) if (dv[i].size() == 0)
    for (int j = i; j <= n; j += i)
      dv[j].emplace_back(i);
  for (int i = k + 1; i <= n; ++i) {
    dp[i] = i;
    for (auto u: dv[i]) dp[i] = std::min(dp[i], dp[i / u] * u + 1);
  }
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    int u; std::cin >> u;
    res += dp[u];
  }
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
