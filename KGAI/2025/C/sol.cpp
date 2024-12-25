/**
 *    author:  feev1x
 *    created: 22.12.2024 13:39:47
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
  std::sort(a.begin(), a.end());
  int r = a[0] + a[1] - 1, l = a[n - 1] - a[0] + 1;
  int cnt = 0;
  if (r >= l) {
    cnt += r - l + 1;
  }
  std::cout << cnt << '\n';
  return 0;
}
