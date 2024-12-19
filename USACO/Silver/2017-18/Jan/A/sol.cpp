/**
 *    author:  feev1x
 *    created: 18.12.2024 16:37:15
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("lifeguards.in", "r", stdin);
  std::freopen("lifeguards.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> seg(n);
  for (int i = 0; i < n; ++i) {
    auto &[l, r] = seg[i];
    std::cin >> l >> r;
    r--;
  }
  std::sort(seg.begin(), seg.end(), [](std::pair<int, int> x, std::pair<int, int> y) {
    if (x.first == y.first) {
      return x.second > y.second;
    }
    return x.first < y.first;
  });
  int mn = 1e9, sz = 0, lr = -1, ll = -1;
  for (auto [l, r]: seg) {
    if (lr >= r || ll >= l) {
      mn = 0;
    }
    if (mn && lr != -1) {
      mn = std::min(mn, std::min(r - std::max(l, lr + 1) + 1, std::min(l - 1, lr) - ll + 1));
    }
    if (mn) {
      mn = std::min(mn, r - l + 1);
    }
    if (lr < r) {
      sz += std::max(0, r - std::max(l, lr + 1) + 1);
    }
    ll = std::max(lr + 1, l), lr = std::max(lr, r);
  }
  std::cout << sz - mn << '\n';
  return 0;
}
