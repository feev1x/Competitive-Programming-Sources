#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, e; std::cin >> n >> e;
  std::vector<std::string> s(n);
  for (auto &u: s) std::cin >> u;
  int res = 1e9, ch = -1;
  for (int le = 0; le < e; ++le) {
    char c = char(le + 'a');
    int ans = 0;
    bool flag = true;
    for (auto u: s) {
      bool fl = false;
      for (auto x: u) {
        if (x != c) {
          fl = true;
          break;
        }
        ans++;
      }
      if (!fl) flag = false;
    }
    if (!flag) continue;
    if (res > ans) res = ans, ch = le;
  }
  if (ch == -1) {
    std::cout << "NO\n";
    return 0;
  }
  while (res--) std::cout << char(ch + 'a');
  std::cout << char(ch + 'a') << '\n';
  return 0;
}
