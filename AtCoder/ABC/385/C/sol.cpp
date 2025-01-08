/**
 *    author:  feev1x
 *    created: 21.12.2024 18:12:26
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) { 
    std::cin >> u;
  }
  int res = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j < n; ++j) {
      int cnt = 0;
      for (int k = i; a[i] == a[k] && k < n; k += j) {
        cnt++;
      }
      res = std::max(res, cnt);
    }
  }
  std::cout << res << '\n';
  return 0;
}
