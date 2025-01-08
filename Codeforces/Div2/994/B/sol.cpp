/**
 *    author:  feev1x
 *    created: 20.12.2024 20:42:05
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    bool flag = false;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'p') {
        flag = true;
      } else if (s[i] == 's' && flag) {
        ans = false;
        break;
      }
    }
    if (!ans) {
      std::cout << "NO\n";
      continue;
    }
    if (!flag || s.find('s') == std::string::npos) {
      std::cout << "YES\n";
      continue;
    }
    std::vector<int> p(n);
    int nw = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 's' || i == 0) {
        for (int j = i; !p[j] && j < n; ++j) {
          p[j] = nw++;
        }
      }
    }
    std::vector<std::vector<int>> cnt(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      if (i) {
        cnt[i] = cnt[i - 1];
      }
      cnt[i][p[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'p') {
        for (int j = 1; j <= i + 1; ++j) {
          if (cnt[i][j] != 1) {
            ans = false;
            break;
          }
        }
      }
    }
    std::cout << (!ans ? "NO\n" : "YES\n");
  }
  return 0;
}
