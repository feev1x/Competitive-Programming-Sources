#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s, t; std::cin >> s >> t;
  int n = s.size(), m = t.size();
  for (int i = 0, j = 0; i < n || j < m; ++i, ++j) {
    if (i >= n || s[i] != t[j]) {
      --i;
      if (i - 1 < 0 || s[i - 1] != s[i] || s[i] != t[j]) {
        std::cout << "NO\n";
        exit(0);
      }
    }
  }
  std::cout << "YES\n";
  return 0;
}
