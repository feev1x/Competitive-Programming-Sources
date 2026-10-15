#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  int ls = 0, c0 = 0, c1 = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != s[ls]) {
      if (s[ls] == '0') c0 += i - ls - 1;
      else c1 += i - ls - 1;
      ls = i;
    }
  }
  if (s[ls] == '0') c0 += n - ls - 1;
  else c1 += n - ls - 1;
  if (std::abs(c1 - c0) > 3) {
    std::cout << "-1\n";
    return;
  }
  if (std::abs(c1 - c0) > 1) {
    if (c1 > c0) {
      if (s.back() == '0') c0++;
    } else {
      if (s.back() == '1') c1++;
    }
  }
  if (std::abs(c1 - c0) > 1) {
    if (c1 > c0) {
      if (s.front() == '0') c0++;
    } else {
      if (s.front() == '1') c1++;
    }
  }
  if (std::abs(c1 - c0) > 1) {
    std::cout << "-1\n";
    return;
  }
  std::cout << c1 + c0 << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
