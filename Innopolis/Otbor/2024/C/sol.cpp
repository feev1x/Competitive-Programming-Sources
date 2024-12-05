/**
 *    author:  feev1x
 *    created: 24.11.2024 15:31:18
**/
#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr int MOD = 998244353;
 
inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
 
int main() {
  int n; scanf("%d", &n);
  std::vector<int> st;
  auto Check = [&](int u) {
    while (u > 0) {
      if (u % 3 == 1) {
        return false;
      }
      u /= 3;
    }
    return true;
  };
  for (int i = 0; i <= n; ++i) {
    if (Check(i)) {
      st.emplace_back(i + 1);
    }
  }
  int dp[n + 1]{};
  dp[0] = 1;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (auto u: st) {
      if (i - u < 0) {
        break;
      }
      add_self(dp[i], dp[i - u]);
      sum++;
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
