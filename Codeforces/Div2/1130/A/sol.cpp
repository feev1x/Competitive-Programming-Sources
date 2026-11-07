#include <bits/stdc++.h>

inline void solve() {
  int n, k, mx = 0; std::cin >> n >> k;
  k = n - k + 1;
  std::vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (i <= k) mx = std::max(mx, a[i]), c[a[i]]++;
  }
  int mex = 0;
  for (int i = 0; i <= n; ++i) {
    if (c[i] == 0) {
      mex = i;
      break;
    }
  }
  if (mex == k) {
    std::cout << "-1\n";
    return;
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == mex) x = i;
    if (a[i] == mx) y = i;
  }
  std::cout << x << ' ' << y << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
