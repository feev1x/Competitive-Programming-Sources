/**
 *    author:  feev1x
 *    created: 26.12.2024 20:14:49
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; char c1, c2; std::cin >> n >> c1 >> c2;
  std::string s; std::cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] != c1) {
      s[i] = c2;
    }
  }
  std::cout << s << '\n';
  return 0;
}
