/**
 *    author:  feev1x
 *    created: 20.12.2024 20:36:13
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    bool zer = false, used = false;
    int cnt = 0;
    for (auto &u: a) {
      std::cin >> u;
      if (u == 0) {
        zer = true;
        used = false;
      } else if (!used) {
        cnt++;
        used = true;
      }
    }
    if (!zer) {
      std::cout << "1\n";
    } else {
      std::cout << std::min(cnt, 2) << '\n';
    }
  }
  return 0;
}
