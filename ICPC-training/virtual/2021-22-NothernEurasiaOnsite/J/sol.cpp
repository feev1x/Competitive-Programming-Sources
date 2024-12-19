/**
 *    author:  feev1x
 *    created: 11.12.2024 10:23:57
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
  int n; scanf("%d", &n);
  std::vector c(n + 1, std::vector<i64>(n + 1)), dp(n + 2, std::vector<i64>(n + 2));
  std::vector op(n + 2, std::vector<i64>(n + 2)), pref(n + 2, std::vector<i64>(n + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld\n", &c[i][j]);
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + c[i][j];
      if (i <= j) {
        dp[i][j] = INF;
      }
    }
  }
  auto Sum = [&](int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x2][y1 - 1] - pref[x1 - 1][y2] + pref[x1 - 1][y1 - 1];
  };
  auto Cost = [&](int l, int r) {
    if (l > r) {
      return 0ll;
    }
    return Sum(l, 1, r, n) - Sum(l, l, r, r);
  };
  for (int sz = 1; sz <= n; ++sz) {
    for (int l = 1, r = l + sz - 1; r <= n; ++l, ++r) {
      for (int k = l; k <= r; ++k) {
        if (dp[l][r] > dp[l][k - 1] + dp[k + 1][r] + Cost(l, k - 1) + Cost(k + 1, r)) {
          dp[l][r] = dp[l][k - 1] + dp[k + 1][r] + Cost(l, k - 1) + Cost(k + 1, r);
          op[l][r] = k;
        }
      }
    }
  }
  std::vector<int> p(n + 1); 
  auto Dfs = [&](auto &&Dfs, int l, int r) -> void {
    if (l >= r) {
      return;
    }
    int k = op[l][r];
    p[op[l][k - 1]] = k;
    p[op[k + 1][r]] = k;
    Dfs(Dfs, l, k - 1);
    Dfs(Dfs, k + 1, r);
  };
  Dfs(Dfs, 1, n);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");
  return 0;
}
