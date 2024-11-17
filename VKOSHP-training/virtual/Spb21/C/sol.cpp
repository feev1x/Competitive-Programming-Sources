/**
 *    author:  feev1x
 *    created: 14.11.2024 13:02:13
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

struct SpTable {
  std::vector<std::vector<i64>> sp;
  std::vector<int> lg;
  int n;
  SpTable(std::vector<i64> a) : n(a.size()) {
    n--;
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<i64>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  inline i64 calc(std::pair<int, int> par) {
    auto [l, r] = par;
    int sz = r - l + 1;
    return std::min(sp[lg[sz]][l], sp[lg[sz]][r - (1 << lg[sz]) + 1]);
  }
};

int main() {
  int n, m; scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> bl(m + 1);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &bl[i].first, &bl[i].second);
  }
  std::vector dp(m + 1, std::vector<i64>(n + 1, INF));
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = abs(bl[1].first - i);
  }
  SpTable sp(dp[1]);
  auto Fun = [&](int i, int j) {
    int l, r;
    int pr = bl[i - 1].second - bl[i - 1].first;
    int pr1 = bl[i].second - bl[i].first;
    l = std::max(j - pr, 1);
    r = std::min(j + pr1, n - pr);
    return std::pair{l, r};
  };
  for (int i = 2; i <= m; ++i) {
    int sz = bl[i].second - bl[i].first + 1;
    for (int j = 1; j + sz - 1 <= n; ++j) {
      dp[i][j] = abs(bl[i].first - j) + sp.calc(Fun(i, j));
    }
    sp = SpTable(dp[i]);
  }
  printf("%lld\n", sp.calc({1, n}));
  return 0;
}
