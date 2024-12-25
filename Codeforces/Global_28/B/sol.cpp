/**
 *    author:  feev1x
 *    created: 19.12.2024 20:38:36
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> p(n);
    int nw = 1;
    for (int i = k - 1; i < n; i += k) {
      p[i] = nw;
      nw++;
    }
    for (int j = n - 1; j >= 0; --j) {
      if (!p[j]) {
        p[j] = nw;
        nw++;
      }
    }
    for (auto u: p) {
      std::cout << u << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
