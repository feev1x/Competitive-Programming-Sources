/**
 *    author:  feev1x
 *    created: 22.12.2024 13:21:01
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
  std::map<int, int> mp;
  for (int i = 1; i < n; ++i) {
    mp[std::abs(a[i] - a[i - 1])]++;
  }
  int D = mp.rbegin()->first, j = 1, ch = a[0];
  if (mp[D] > 2) {
    std::cout << D << ' ' << j << ' ' << ch << '\n';
    exit(0);
  }
  for (int i = 0; i < n; ++i) {
    if (std::abs(a[i] - a[i - 1]) != D && std::abs(a[i] - a[i + 1]) != D) {
      continue;
    }
    int val = -1;
    if (i) {
      mp[std::abs(a[i] - a[i - 1])]--;
      if (!mp[std::abs(a[i] - a[i - 1])]) {
        mp.erase(std::abs(a[i] - a[i - 1]));
      }
      val = a[i - 1];
    } else {
      val = a[i + 1];
    }
    if (i + 1 < n) {
      mp[std::abs(a[i] - a[i + 1])]--;
      if (!mp[std::abs(a[i] - a[i + 1])]) {
        mp.erase(std::abs(a[i] - a[i + 1]));
      }
      val = (val + a[i + 1]) / 2;
    }
    int max = 0;
    if (i) {
      max = std::max(max, std::abs(val - a[i - 1]));
    }
    if (i + 1 < n) {
      max = std::max(max, std::abs(val - a[i + 1]));
    }
    if (D > std::max(mp.rbegin()->first, max)) {
      D = mp.rbegin()->first;
      j = i + 1;
      ch = val;
    }
    if (i) {
      mp[std::abs(a[i] - a[i - 1])]++;
    }
    if (i + 1 < n) {
      mp[std::abs(a[i] - a[i + 1])]++;
    }
  }
  std::cout << D << ' ' << j << ' ' << ch << '\n';
  return 0;
}
