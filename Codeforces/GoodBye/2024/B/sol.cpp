/**
 *    author:  feev1x
 *    created: 28.12.2024 20:43:57
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> l(n), r(n);
    std::vector<int> a;
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      std::cin >> l[i] >> r[i];
      if (l[i] == r[i]) {
        if (!mp[l[i]]) {
          a.emplace_back(l[i]);
        }
        mp[l[i]]++;
      }
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      if (l[i] == r[i]) {
        std::cout << (mp[l[i]] == 1);
        continue;
      }
      int left = std::lower_bound(a.begin(), a.end(), l[i]) - a.begin();
      int right = std::upper_bound(a.begin(), a.end(), r[i]) - a.begin();
      std::cout << (r[i] - l[i] + 1 != right - left);
    }
    std::cout << '\n';
  }
  return 0;
}
