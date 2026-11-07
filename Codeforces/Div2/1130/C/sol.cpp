#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
  int n, x; std::cin >> n >> x;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int m = l + r >> 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i && a[i] - a[i - 1] <= m || i + 1 < n && a[i + 1] - a[i] <= m) continue;
      int j = a[i] + m;
      cnt++;
      if (i + 1 < n && a[i + 1] - j <= m) i++;
    }
    if (cnt <= x) r = m - 1, ans = m;
    else l = m + 1;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
