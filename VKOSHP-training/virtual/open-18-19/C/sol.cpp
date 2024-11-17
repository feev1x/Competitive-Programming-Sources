/**
 *    author:  feev1x
 *    created: 15.11.2024 12:21:07
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int INF = 2e9 + 7;

inline void min_self(int &a, int b) {
  if (a > b) {
     a = b;
  }
}

inline void max_self(int &a, int b) {
  if (a < b) {
     a = b;
  }
}

int Solve(std::vector<int> t, std::vector<int> p, int mx, int mn) {
  if (t.empty()) return 0;
  std::vector<int> dp(mx);
  int n = t.size();
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    auto new_dp = dp;
    for (int j = t[i]; j < mx; ++j) {
      max_self(new_dp[j], dp[j - t[i]] + p[i]);
    }
    dp = new_dp;
  }
  int res = -INF;
  for (int i = mn; i < mx; ++i) {
    max_self(res, dp[i]);
  }
  return res;
};

signed main() {
  int n, T; scanf("%d%d", &n, &T);
  std::vector<int> t(n + 1), p(n + 1), mnf(n + 1), pt(n + 1), pp(n + 1);
  int mn = INF;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t[i], &p[i]);
    if (i) pt[i] = pt[i - 1], pp[i] = pp[i - 1];
    pt[i] += t[i], pp[i] += p[i];
  }
  auto Sort = [](std::vector<int> t, std::vector<int> p) {
    std::vector<std::pair<int, int>> pr;
    for (int i = 0; i < t.size(); ++i) {
      pr.emplace_back(t[i], p[i]);
    }
    std::sort(pr.begin(), pr.end(), std::greater<>());
    for (int i = 0; i < pr.size(); ++i) {
      std::tie(t[i], p[i]) = pr[i];
    }
    return std::pair{t, p};
  };
  std::tie(t, p) = Sort(t, p);
  int res = INF;
  for (int mn = 0; mn < n; ++mn) {
    std::vector<int> t1, p1;
    for (int i = mn + 1; i < n; ++i) {
      t1.emplace_back(t[i]);
      p1.emplace_back(p[i]);
    }
    res = std::min(res, (mn ? pp[mn - 1] : 0) + pp[n - 1] - pp[mn] - 
        Solve(t1, p1, pt[n - 1] - T, pt[n - 1] - T - t[mn]));
  }
  printf("%d\n", res);
  return 0;
}
