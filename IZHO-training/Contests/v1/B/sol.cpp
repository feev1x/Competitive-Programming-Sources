/**
 *    author:  feev1x
 *    created: 05.01.2025 15:48:20
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e6 + 5;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<bool> prime(N, true);
  std::array<int, 4> mx{2, 1, 2, 3};
  std::vector<int> cnt(N);
  cnt[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (prime[i]) {
      for (int j = i * 2; j < N; j += i) {
        prime[j] = false;
      }
      mx[i % 4] = i;
    }
    cnt[i] = (i - mx[i % 4]) / 2 + 1;
  }
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    bool flag = false;
    int res = N;
    for (auto &u: a) {
      std::cin >> u;
      if (res / 2 > cnt[u] / 2) {
        res = cnt[u];
      }
    }
    std::cout << "Farmer " << (res & 1 ? "John\n" : "Nhoj\n");
  }
  return 0;
}
