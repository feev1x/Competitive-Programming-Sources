#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  int64_t res = -1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] == a[i + 1]) {
      for (int s = 0; s < n; ++s) if (s < i || s > i + 1) {
        for (int b = 0; b < n; ++b) if ((b < i || b > i + 1) && b != s) {
          res = std::max(res, (int64_t)a[i] * 2 + a[s] + a[b]);
        }
      }
      break;
    }
  }
  std::cout << res << '\n';
  return 0;
}
