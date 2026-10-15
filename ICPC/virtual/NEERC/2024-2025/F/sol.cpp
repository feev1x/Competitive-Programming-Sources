#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> tm;
  for (int i = 0; i < n; ++i) {
    std::string s; std::cin >> s;
    tm.emplace_back((s[0] - '0') * 60 + (s[2] - '0') * 10 + s[3] - '0');
  }
  for (int i = 2; i < n; ++i) if (tm[i] - tm[i - 2] <= 10) return std::cout << "0\n", 0;
  for (int i = 1; i < n; ++i) if (tm[i] - tm[i - 1] <= 10) return std::cout << "1\n", 0;
  std::cout << "2\n";
  return 0;
}
