#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  std::cout << std::gcd(a.front(), a.back()) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
