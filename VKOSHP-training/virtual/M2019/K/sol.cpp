/**
 *    author:  feev1x
 *    created: 12.11.2024 17:27:10
**/
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned i64;
using i128 = __int128;
using u128 = unsigned i128;

constexpr int MXA = 25e5 + 5;
using bs = std::bitset<MXA>;

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a;
  int sum = 0;
  for (int i = 0; i < 2 * n; ++i) {
    int u; scanf("%d", &u);
    sum += u;
    a.emplace_back(u);
  }
  std::sort(a.begin(), a.end());
  a.emplace(a.begin(), 0);
  std::vector dp(2 * n + 1, std::vector<bs>(n + 2));
  dp[2][2].set(a[1] + a[2]);
  for (int i = 3; i <= 2 * n; ++i) {
    for (int j = 2; j <= n; ++j) {
      for (int k = 2; k < i; ++k) {
        dp[i][j + 1] |= dp[k][j] << a[i];
      }
    }
  }
  int res = (i64)INT_MAX - 5, opt = -1;
  for (int i = n + 1; i <= 2 * n; ++i) {
    for (int j = a[1] + a[2]; j <= sum; ++j) {
      if (dp[i][n + 1][j]) {
        if (res > std::max(j, sum - (j - a[1] - a[2]))) {
          opt = i;
          res = std::max(j, sum - (j - a[1] - a[2]));
        }
      }
    }
  }
  std::vector<int> sd1, sd2;
  std::vector<bool> used(2 * n + 1);
  used[1] = true;
  for (int i = 2 * n, j = n + 1, nd = res; i >= 3; --i) {
    if (dp[i][j][nd]) {
      j--;
      nd -= a[i];
      std::cerr << i << '\n';
      used[i] = true;
    }
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (used[i]) {
      sd1.emplace_back(a[i]);
    } else {
      sd2.emplace_back(a[i]);
    }
  }
  std::sort(sd1.begin(), sd1.end());
  std::sort(sd2.begin(), sd2.end(), std::greater<>());
  for (auto u: sd1) {
    printf("%d ", u);
  }
  printf("\n");
  for (auto u: sd2) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
