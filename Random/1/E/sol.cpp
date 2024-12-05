/**
 *    author:  feev1x
 *    created: 30.11.2024 12:13:24
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int S = 1e4 + 1;

using bs = std::bitset<S>;

int main() {
  int s, n; scanf("%d%d", &s, &n);
  std::vector<int> a(n);
  bs dp;
  dp[0] = true;
  for (auto &u: a) {
    scanf("%d", &u);
    dp |= dp << u;
  }
  for (int i = s; i >= 0; --i) {
    if (dp[i]) {
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}
