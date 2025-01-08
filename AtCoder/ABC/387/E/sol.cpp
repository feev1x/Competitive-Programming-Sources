/**
 *    author:  feev1x
 *    created: 04.01.2025 19:20:42
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s; std::cin >> s;
  std::string t(s.size(), '0');
  t[0] = '1';
  if (s.size() == 1 || s == t) {
    std::cout << s << '\n';
    exit(0);
  }
  t[0] = '2';
  if (s[0] == '1' || s == t) {
    std::cout << t << '\n';
    exit(0);
  }
  t[0] = '3', t[1] = '6';
  if (s[0] == '2' || s[0] == '3' && s[1] < '6' || s == t) {
    std::cout << t << '\n';
    exit(0);
  }

  return 0;
}
