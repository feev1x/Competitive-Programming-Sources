#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s, c; std::cin >> s >> c;
  for (int i = 0; ; ++i) {
    int s1 = (int)s.size() - i - 1, s2 = (int)s.size() - s1;
    if (std::abs(s2 - (s1 + (int)c.size() - 1)) <= 1 && s2 >= (s1 + (int)c.size() - 1)) {
      std::cout << s.substr(0, s2) << ' ' << s.substr(i + 1, s1) << '\n';
      break;
    }
  }
  return 0;
}
