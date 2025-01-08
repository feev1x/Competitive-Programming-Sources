/**
 *    author:  feev1x
 *    created: 19.12.2024 20:42:30
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    std::string s; std::cin >> s;
    int n = s.size();
    int l1 = 1, r1 = n, l2, r2;
    std::string opt;
    if (n == 1) {
      std::cout << "1 1 1 1\n";
      continue;
    }
    int pos = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      std::cout << "1 1 1 " << n << '\n';
      continue;
    }
    int sz = n - pos;
    auto IsBig = [&](std::string s1, std::string s2) {
      if (s2.empty()) {
        return true;
      }
      for (int i = pos, j = 0; i < n; ++i, ++j) {
        if (s1[j] != s2[j]) {
          if (s[i] != s1[j]) {
            return true;
          }
          return false;
        }
      }
      return false;
    };
    for (int i = 0; i + sz - 1 < n; ++i) {
      if (s[i] == '0') {
        continue;
      }
      std::string s1;
      for (int j = i; j < i + sz; ++j) {
        s1 += s[j];
      }
      if (IsBig(s1, opt)) {
        l2 = i + 1, r2 = i + sz;
        opt = s1;
      }
    }
    std::cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
  }
  return 0;
}
