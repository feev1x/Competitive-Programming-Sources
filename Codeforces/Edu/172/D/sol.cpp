/**
 *    author:  feev1x
 *    created: 02.12.2024 22:06:26
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
#define int i64
  while (tt--) {
    int n; scanf("%lld", &n);
    std::vector<std::tuple<int, int, int>> seg(n);
    std::vector<std::pair<int, int>> sg(n);
    for (int i = 0; i < n; ++i) {
      auto &[l, r, j] = seg[i];
      scanf("%lld%lld", &l, &r);
      sg[i] = {l, r};
      j = i;
    }
    std::sort(seg.begin(), seg.end(), [](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
        if (std::get<0>(a) == std::get<0>(b)) {
          return std::get<1>(a) > std::get<1>(b);
        }
        return std::get<0>(a) < std::get<0>(b);
        });
    std::set<int> rg;
    std::map<int, std::map<int, int>> lf, rt;
    for (auto [l, r, j]: seg) {
      if (rg.empty()) {
        rt[l][r] = r;
      } else {
        auto it = rg.lower_bound(r);
        if (it == rg.end()) {
          rt[l][r] = r;
        } else {
          rt[l][r] = *it;
        }
      }
      rg.emplace(r);
    }
    std::sort(seg.begin(), seg.end(), [](std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
        if (std::get<1>(a) == std::get<1>(b)) {
          return std::get<0>(a) < std::get<0>(b);
        }
        return std::get<1>(a) > std::get<1>(b);
        });
    rg.clear();
    for (auto [l, r, j]: seg) {
      if (rg.empty()) {
        lf[l][r] = l;
      } else {
        auto it = rg.upper_bound(l);
        if (it == rg.begin()) {
          lf[l][r] = l;
        } else {
          lf[l][r] = *--it;
        }
      }
      rg.emplace(l);
    }
    for (int i = 0; i < n; ++i) {
      auto [l, r] = sg[i];
      printf("%lld\n", (l - lf[l][r]) + (rt[l][r] - r));
    }
  }
  return 0;
}
