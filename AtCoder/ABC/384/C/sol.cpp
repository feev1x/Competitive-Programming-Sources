/**
 *    author:  feev1x
 *    created: 26.12.2024 20:21:32
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string str = "ABCDE";

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<std::pair<int, std::string>> ar;
  std::vector<int> a(5);
  for (auto &u: a) {
    std::cin >> u;
  }
  for (int mask = 0; mask < (1 << 5); ++mask) {
    std::string s;
    int score = 0;
    for (int i = 0; i < 5; ++i) {
      if (mask >> i & 1) {
        score -= a[i];
        s += str[i];
      }
    }
    ar.emplace_back(score, s);
  }
  std::sort(ar.begin(), ar.end());
  for (auto [__, s]: ar) {
    std::cout << s << '\n';
  }
  return 0;
}
