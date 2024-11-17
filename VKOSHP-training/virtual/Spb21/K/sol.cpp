/**
 *    author:  feev1x
 *    created: 14.11.2024 10:06:06
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  double x, t; scanf("%lf%lf", &x, &t);
  double l = 0, r = t, ans = 0;
  int num = 100;
  auto Solve = [&](double m) {
    double work = t - m;
    if (m >= t / 3) {
      return work * 100;
    }
    if (m >= t / 6) {
      m -= t / 6;
      double juz = 100 - x;
      double tm = t / 3 - t / 6;
      double pr = m / tm;
      return (x + pr * juz) * work;
    }
    double pr = m / (t / 6);
    return pr * x * work;
  };
  while (num--) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double ans1 = Solve(m1), ans2 = Solve(m2);
    ans = std::max({ans, ans1, ans2});
    std::cerr << m1 << ' ' << m2 << '\n';
    if (ans1 > ans2) {
      r = m2 - 1e-8;
    } else {
      l = m1 + 1e-8;
    }
  }
  printf("%.7lf\n", ans);
  return 0;
}
