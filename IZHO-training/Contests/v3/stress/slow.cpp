/**
 *    author:  feev1x
 *    created: 28.12.2024 12:17:56
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> p(n + 1);
  for (int i = 2; i <= n; ++i) {
    std::cin >> p[i];
  }
  return 0;
}
