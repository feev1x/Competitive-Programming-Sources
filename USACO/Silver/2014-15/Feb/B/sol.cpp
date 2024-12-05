/**
 *    author:  feev1x
 *    created: 28.11.2024 19:19:33
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int main() {
  std::freopen("hopscotch.in", "r", stdin);
  std::freopen("hopscotch.out", "w", stdout);
  int r, c, k; scanf("%d%d%d", &r, &c, &k);
  std::vector a(r + 1, std::vector<int>(c + 1));
  std::vector dp(r + 1, std::vector<int>(c + 1));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  dp[1][1] = 1;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      for (int i1 = 1; i1 < i; ++i1) {
        for (int j1 = 1; j1 < j; ++j1) {
          add_self(dp[i][j], dp[i1][j1] * (a[i1][j1] != a[i][j]));
        }
      }
    }
  }
  printf("%d\n", dp[r][c]);
  return 0; 
}
