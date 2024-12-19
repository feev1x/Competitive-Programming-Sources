/**
 *    author:  feev1x
 *    created: 08.12.2024 12:23:44
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  i64 C; int n; scanf("%lld%d", &C, &n);
  std::array<std::vector<std::pair<i64, i64>>, 2> dp;
  std::array<std::vector<int>, 2> p;
  std::vector<i64> a(n), b(n);
  for (auto &u: a) {
    scanf("%lld", &u);
  }
  for (auto &u: b) {
    scanf("%lld", &u);
  }
  auto Check = [&](std::pair<i64, i64> &x, std::pair<i64, i64> y, int v, int i) {
    if (v == 0) {
      y.second += y.first * a[i - 1];
      y.first = 0;
      if (x.second < y.second || x.second == y.second && x < y) {
        x = y;
        return true;
      }
    } else {
      y.first += y.second / b[i - 1];
      y.second %= b[i - 1];
      if (x < y) {
        x = y;
        return true;
      }
    }
    return false;
  };
  for (int i = 0; i < 2; ++i) {
    dp[i].resize(n + 1);
    p[i].resize(n + 1);
    dp[i][0] = {C, 0};
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (Check(dp[j][i], dp[k][i - 1], j, i)) {
          p[j][i] = k;
        }
      }
    }
  }
  printf("%lld\n", dp[0][n].second);
  std::string s = "A";
  int j = 0;
  for (int i = n; i > 1; --i) {
    int k = p[j][i];
    s += char('A' + k);
    j = k;
  }
  std::reverse(s.begin(), s.end());
  printf("%s\n", s.c_str());
  return 0;
}
