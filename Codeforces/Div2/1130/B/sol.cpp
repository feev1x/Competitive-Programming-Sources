#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::string s, t; std::cin >> s >> t;
  int cnt = std::count(s.begin(), s.end(), 'f') + std::count(t.begin(), t.end(), 'f');
  std::cout << (cnt & 1) << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
