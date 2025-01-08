/**
 *    author:  feev1x
 *    created: 21.12.2024 19:01:16
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr long double INF = 1e18;

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<long double> x(n), h(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> h[i];
  }
  bool flag = false;
  long double mx = -INF;
  for (int i = 0; i < n; ++i) {
    long double slope = h[i] / x[i];
    if (mx >= slope) {
      flag = true;
      break;
    }
    mx = slope;
  }
  long double ans = 0;
  for (int i = 1; i < n; ++i) {
    long double slope = (h[i - 1] - h[i]) / (x[i - 1] - x[i]);
    ans = std::max(ans, (-slope) * x[i - 1] + h[i - 1]);
  }
  if (!flag) {
    std::cout << "-1\n";
  } else {
    std::cout << std::fixed << std::setprecision(12) << ans << '\n';
  }
  return 0;
}
