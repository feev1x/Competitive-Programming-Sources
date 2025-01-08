/**
 *    author:  feev1x
 *    created: 05.12.2024 20:45:17
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e5 + 5;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    scanf("%s", S);
    std::string s = S;
    int sum = 0;
    std::array<bool, 9> dp{};
    dp[0] = true;
    for (int i = 0; i < s.size(); ++i) {
      sum += (s[i] - '0');
      sum %= 9;
      int u = s[i] - '0', st = s[i] - '0';
      auto new_dp = dp;
      u *= u;
      while (u >= 2 && u < 10) {
        for (int j = 0; j < 9; ++j) {
          if (dp[j]) {
            new_dp[(j + u - st) % 9] = true;
          }
        }
        u *= u;
      }
      dp = new_dp;
    }
    if (dp[(9 - sum) % 9]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
