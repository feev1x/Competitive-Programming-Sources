#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  char c; std::cin >> c;
  std::string s = "BYRBYRB";
  for (int i = 0; ; ++i) {
    if (c == s[i]) {
      std::cout << s[i + 1] << '\n';
      return 0;
    }
  }
  return 0;
}
