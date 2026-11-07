#include <bits/stdc++.h>

inline void solve () {
  int n, m, q; std::cin >> n >> m >> q;
  std::vector<int> l(m + 1), r(m + 1);
  Segtree t(n);
  for (
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
