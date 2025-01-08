/**
 *    author:  feev1x
 *    created: 05.12.2024 21:43:48
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e3 + 3, INF = 1e9;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    std::string a, b, c;
    scanf("%s", S); a = S;
    scanf("%s", S); b = S;
    scanf("%s", S); c = S;
    int n = a.size(), m = b.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, INF));
    dp[0][0] = 0;
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      if (i < n && dp[i + 1][j] > dp[i][j] + (c[i + j] != a[i])) {
        dp[i + 1][j] = dp[i][j] + (c[i + j] != a[i]);
        q.emplace(i + 1, j);
      }
      if (j < m && dp[i][j + 1] > dp[i][j] + (c[i + j] != b[j])) {
        dp[i][j + 1] = dp[i][j] + (c[i + j] != b[j]);
        q.emplace(i, j + 1);
      }
    }
    printf("%d\n", dp[n][m]);
  }
  return 0;
}
