/**
 *    author:  feev1x
 *    created: 10.11.2024 19:45:02
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  char S[101]; scanf("%s", S);
  std::string s = S;
  int n = s.size();
  std::vector dp(n, std::vector<std::deque<char>>(n));
  std::map<char, char> mp;
  mp['('] = ')';
  mp['['] = ']';
  mp['{'] = '}';
  auto Max = [](std::deque<char> dq, std::deque<char> dq1) {
    if (dq.size() > dq1.size()) {
      return dq;
    }
    return dq1;
  };
  auto Comb = [](std::deque<char> dq, std::deque<char> dq1) {
    std::deque<char> ans;
    for (auto u: dq) {
      ans.emplace_back(u);
    }
    for (auto u: dq1) {
      ans.emplace_back(u);
    }
    return ans;
  };
  for (int sz = 2; sz <= n; ++sz) {
    for (int l = 0; l + sz <= n; ++l) {
      int r = l + sz - 1;
      dp[l][r] = dp[l + 1][r - 1];
      if (s[r] == mp[s[l]]) {
        dp[l][r].emplace_front(s[l]);
        dp[l][r].emplace_back(s[r]);
      }
      dp[l][r] = Max(dp[l][r], dp[l + 1][r]);
      dp[l][r] = Max(dp[l][r], dp[l][r - 1]);
      for (int mid = l; mid < r; ++mid) {
        dp[l][r] = Max(dp[l][r], Comb(dp[l][mid], dp[mid + 1][r]));
      }
    }
  }
  for (auto u: dp[0][n - 1]) {
    printf("%c", u);
  }
  printf("\n");
  return 0;
}
