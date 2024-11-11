/**
 *    author:  feev1x
 *    created: 10.11.2024 17:42:58
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

inline void min_self(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  char S[1001]; scanf("%s", S);
  std::string s = S;
  scanf("%s", S);
  std::string t = S;
  int n = s.size(), m = t.size();
  std::vector dp(n + 1, std::vector<int>(m + 1, 1e9));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= m; ++i) {
    dp[0][i] = i;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        min_self(dp[i][j], dp[i - 1][j - 1]);
      } else {
        min_self(dp[i][j], dp[i - 1][j - 1] + 1);
        min_self(dp[i][j], dp[i - 1][j] + 1);
        min_self(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  printf("%d\n", dp[n][m]);
  return 0;
}
