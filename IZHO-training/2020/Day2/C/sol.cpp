/**
 *    author:  feev1x
 *    created: 24.12.2024 09:22:31
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::vector<i64> a(n);
  for (auto &u: a) {
    std::cin >> u;
  }
  a.erase(std::unique(a.begin(), a.end()), a.end());
  n = a.size();
  int B = sqrt(n) + 1;
  std::vector<std::pair<int, int>> L(q), R(q);
  std::vector<std::vector<i64>> dp(B + 1, std::vector<i64>(B + 1));
  std::vector<std::vector<i64>> left(B + 1, std::vector<i64>(B + 1));
  std::vector<std::vector<i64>> right(B + 1, std::vector<i64>(B + 1));
  for (int i = 0; i < n; i += B) {
    if (i + B < n) {
      std::sort(a.begin() + i, a.begin() + i + B);
    } else {
      std::sort(a.begin() + i, a.end());
    }
    int cnt = 0;
    for (int j = i + 1; j < std::min(n, i + B); ++j) {
      if (a[i] == a[i - 1]) {
        cnt++;
      }
    }
  }
  return 0;
}
