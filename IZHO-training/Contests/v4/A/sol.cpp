/**
 *    author:  feev1x
 *    created: 08.01.2025 10:17:01
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<i64> a(n + 1), pref(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  std::vector<std::tuple<i64, int, int>> sum;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      sum.emplace_back(pref[r] - pref[l - 1], l, r);
    }
  }
  std::sort(sum.begin(), sum.end());
  for (int i = 1; i <= n; ++i) {
    i64 res = std::abs(a[i]);
    std::queue<i64> in, out;
    for (auto [sm, l, r]: sum) {
      if (l <= i && i <= r) {
        in.emplace(sm);
      } else {
        out.emplace(sm);
      }
    }
    while (in.size() && out.size()) {
      res = std::min(res, std::abs(in.front() - out.front()));
      if (in.front() > out.front()) {
        out.pop();
      } else {
        in.pop();
      }
    }
    std::cout << res << '\n';
  }
  return 0;
}
