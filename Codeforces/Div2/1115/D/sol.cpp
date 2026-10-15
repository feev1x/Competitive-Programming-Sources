#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<int64_t> a(n);
  for (auto &u: a) std::cin >> u;
  for (int i = 1; i + 1 < n; ++i) {
    if ((a[i - 1] & 1) == (a[i + 1] & 1)) {
      a[i] = std::min(a[i], a[i - 1] - a[i] + a[i + 1]);
    }
  }
  for (int i = n - 2; i > 0; --i) if ((a[i - 1] & 1) == (a[i + 1] & 1)) a[i] = std::min(a[i], a[i - 1] - a[i] + a[i + 1]);
  for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
