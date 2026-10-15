#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  int tm = 0;
  for (int i = 0; i < n; ++i) {
    std::string s; std::cin >> s;
    int m = (s[0] - '0') * 10 + s[1] - '0';
    tm += (s[3] - '0') * 10 + s[4] - '0' + m * 60;
  }
  int s = tm % 60, m = tm / 60, h = m / 60;
  m %= 60;
  std::cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << ':' << s / 10 << s % 10;
  return 0;
}
