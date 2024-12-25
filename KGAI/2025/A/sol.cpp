/**
 *    author:  feev1x
 *    created: 22.12.2024 13:13:40
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  std::set<std::tuple<int, int, int>> sta, stb;
  for (auto &u: a) {
    std::cin >> u;
  }
  for (auto &u: b) {
    std::cin >> u;
  }
  for (int i = 0; i < n; ++i) {
    sta.emplace(-a[i], -b[i], i);
    stb.emplace(-b[i], -a[i], i);
  }
  for (int i = 0; i < n; ++i) {
    int u; std::cin >> u;
    int A, B, I;
    if (u == 1) {
      std::tie(B, A, I) = *stb.begin();
    } else {
      std::tie(A, B, I) = *sta.begin();
    }
    sta.erase({A, B, I});
    stb.erase({B, A, I});
    std::cout << I + 1 << " \n"[i == n - 1];
  }
  return 0;
}
